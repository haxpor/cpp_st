/**
 * Inspired from the book C++ Concurrency in Action by Anthony Williams.
 *
 * This testcase is more like a practice to implement a scope-guard for std::thread
 * to ensure it calls join() if it is still joinable.
 *
 * Compile:
 * g++ -std=c++17 <source-file> -lpthread
 */
#include <thread>
#include <iostream>

class thread_guard
{
public:
	thread_guard(std::thread& t) : m_thread(t)
	{
	}
	
	~thread_guard()
	{
		if (m_thread.joinable())
		{
			std::cout << "[thread_guard] automatically call join()" << std::endl;
			m_thread.join();
		}
	}

	thread_guard(const thread_guard&) = delete;
	thread_guard& operator=(const thread_guard&) = delete;

private:
	std::thread& m_thread;
};

void foo()
{
	std::cout << "foo called" << std::endl;
}

int main()
{
	std::thread t(foo);
	thread_guard guard(t);	// accepts only lvalue reference
	// automatically join() by thread_guard
	return 0;
}
