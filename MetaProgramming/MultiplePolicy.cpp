/**
 * Multiple policy classes.
 *
 * I've tried by using interface classes inside policy classes and it didn't turn out
 * well as we lost compile time capability. I think we should be starting from
 * the template (compile time), not from architectural point of view then try
 * to convert them into compile time. The latter might not be possible, and defeat
 * the purpose of template meta programming.
 *
 * Caution and balancing are needed here though.
 *
 * Compile with
 * g++ -std=c++17 -Wall -Wextra -pedantic -g MultiplePolicy.cpp -lpthread
 *
 * Note that, try to avoid using -O2 or possibly other optimization level as we
 * might need larger increment value for LoopInc in testing for multi-threading sub-test.
 */
#include <cassert>
#include <cstring>
#include <mutex>
#include <atomic>
#include <type_traits>
#include <iostream>
#include <thread>
#include <vector>
#include <utility>

// --- underlying managed obj --- //
struct Widget
{
	Widget() noexcept :
	   m_val(0)
	{}

	Widget(int v) noexcept :
		m_val(v)
	{}

	void PrintVal() const
	{
		std::cout << m_val << std::endl;
	}

	void LoopInc(int l)
	{
		for (int i=0; i<l; ++i)
		{
			++m_val;
		}
	}

	int m_val;
};

// --- checking policy classes --- //
template <class T>
struct NoCheckingPolicy
{
	static void Check(T*) {}
};

template <class T>
struct EnforceNotNullPolicy
{
	class NullPointerException : public std::exception
	{
    public:
		virtual const char* what() const noexcept override
		{
			return "Pointer cannot be null";
		}
	};

	static void Check(T* ptr)
	{
		if (!ptr) throw NullPointerException();
	}
};

template <class T>
struct EnsureNotNullPolicy
{
	static void Check(T*& ptr)
	{
		if (!ptr)
			ptr = GetDefaultValue();
	}

	template <class U=T,
			  typename std::enable_if_t<std::is_constructible_v<U> && std::is_nothrow_default_constructible_v<U>>* = nullptr >
	static U* GetDefaultValue()
	{
		return new U();
	}
};

// --- multi-threading policy classes --- //
template <class T>
struct NoLockPolicy
{
	NoLockPolicy(T* obj):
		m_managedObj(obj)
	{
	}
	~NoLockPolicy() = default;

	T* operator->() const
	{
		return m_managedObj;
	}

private:
	T* m_managedObj;
};

template <class T>
struct ScopedMutexLockPolicy
{
	ScopedMutexLockPolicy(T* obj, std::mutex& mutex):
		m_mutex(mutex),
		m_managedObj(obj)
	{
		m_mutex.lock();
	}
	~ScopedMutexLockPolicy()
	{
		m_mutex.unlock();
	}

	T* operator->() const
	{
		return m_managedObj;
	}

private:
	std::mutex& m_mutex;
	T* m_managedObj;
};

template
<
	class T,
	template <class> class CheckingPolicy = NoCheckingPolicy,
	template <class> class LockingPolicy = NoLockPolicy
>
class SmartPtr
{
public:
	// automatically create an object instance for user if not specified
	SmartPtr():
		m_managedObj(new T())	// this is still exception safe, but just that user would need to catch exception externally for this call
	{}

	SmartPtr(T* obj):
		m_managedObj(obj)
	{}

	~SmartPtr()
	{
		if (m_managedObj)
		{
			delete m_managedObj;
			m_managedObj = nullptr;
		}
	}

	template <typename LU=LockingPolicy<T>,
			  typename std::enable_if_t<std::is_same_v<LU, ScopedMutexLockPolicy<T>>>* = nullptr>
	LU operator->()
	{
		CheckingPolicy<T>::Check(m_managedObj);
		return LU(m_managedObj, m_mutex);
	}

	template <typename LU=LockingPolicy<T>,
			  typename std::enable_if_t<!std::is_same_v<LU, ScopedMutexLockPolicy<T>>>* = nullptr>
	LU operator->()
	{
		CheckingPolicy<T>::Check(m_managedObj);
		return LU(m_managedObj);
	}

private:
	T* m_managedObj;

	// CAVEAT: we can specialize this template for both NoLockPolicy, and ScopedMutexLockPolicy to avoid
	// having to incur declaration of this mutex thus slightly increased the size of SmartPtr
	std::mutex m_mutex;
};

int main()
{
	{
		SmartPtr<Widget> wPtr;
		wPtr->m_val = 10;
		assert(wPtr->m_val == 10);
		wPtr->PrintVal();
	}
	{
		Widget* objPtr = new Widget();
		SmartPtr<Widget> wPtr(objPtr);
		wPtr->m_val = 10;
		assert(wPtr->m_val == 10);
		wPtr->PrintVal();
	}
	{
		Widget* objPtr = nullptr;
		SmartPtr<Widget, EnforceNotNullPolicy> wPtr(objPtr);
		try
		{
			wPtr->m_val = 10;
		}
		catch (EnforceNotNullPolicy<Widget>::NullPointerException& e)
		{
			std::cerr << e.what() << std::endl;
		}
	}
	{
		Widget* objPtr = nullptr;
		SmartPtr<Widget, EnsureNotNullPolicy> wPtr(objPtr);
		wPtr->m_val = 10;
		assert(wPtr->m_val == 10);
	}
	{
		SmartPtr<Widget, EnforceNotNullPolicy, ScopedMutexLockPolicy> wPtr1;

		constexpr std::size_t kNumThread = 100;
		std::vector<std::thread> threads;
		threads.reserve(kNumThread);

		for (int i=0; i<kNumThread; ++i)
		{
			threads.push_back(std::move(std::thread([&wPtr1](){
					wPtr1->LoopInc(10000);
				}
			)));
		}

		// apply fuzzy to wait from last thread to the first
		for (int i=kNumThread-1; i>=0; --i)
		{
			threads[i].join();
		}

		assert(wPtr1->m_val == 1000000);
	}

	return 0;
}
