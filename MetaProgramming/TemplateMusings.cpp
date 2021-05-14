/**
 * Play around with templates included the following
 * - std::is_same
 * - std::is_integral
 * - std::is_arithmetic
 * - std::is_base_of
 * - std::is_convertible
 */
#include <unordered_map>
#include <memory>
#include <cassert>
#include <iostream>
#include <type_traits>
#include <cmath>
#include <cstring>
#include <string>
#include <cstdlib>

// to accommodate generic usage, and data storage
struct IWidget
{
};

template <class T>
struct Widget : public IWidget
{
	using value_type = T;

	Widget() = default;
	Widget(T val):
		m_val(val)
	{}

	Widget& operator= (const T& v)
	{
		m_val = v;
		return *this;
	}

	Widget& operator= (const T&& v)
	{
		m_val = std::move(v);
		return *this;
	}

	// const char*
	template <typename U=T,
			  typename std::enable_if_t<std::is_same_v<U, const char*>>* = nullptr >
	operator const char*() const { return m_val; }

	template <typename U=T,
			  typename std::enable_if_t<std::is_same_v<U, const char*>>* = nullptr >
	operator std::string() const { return std::string(m_val); }
	// CAVEAT: this will return zero even if the conversion cannot be done successfully
	template <typename U=T,
			  typename TARGET,
			  typename std::enable_if_t<std::is_arithmetic_v<TARGET> && std::is_same_v<U, const char*>>* = nullptr >
	operator TARGET() const { return std::atof(m_val); }

	// std::string
	template <typename U=T,
			  typename std::enable_if_t<std::is_same_v<U, std::string>>* = nullptr >
	operator std::string() const { return m_val; }

	template <typename U=T,
			  typename std::enable_if_t<std::is_same_v<U, std::string>>* = nullptr >
	operator const char*() const { return m_val.c_str(); }

	// integral
	template <typename U=T,
			  typename TARGET,
			  typename std::enable_if_t<std::is_integral_v<U> && std::is_arithmetic_v<TARGET>>* = nullptr >
	operator TARGET() const { return static_cast<TARGET>(m_val); }

	T m_val;
};

template <typename HASH_TYPE>
class WidgetManager
{
public:
	// NOTE: not directly using string literal here as we need compile time hashing function, so just directly use numeric here
	template <HASH_TYPE hashVal, class T>
	void Add(Widget<T>& e)
	{
		// convert from reference to pointer then assign as value into hashmap
		m_hashMap[hashVal] = &e;
	}

	template <HASH_TYPE hashVal, class T>
	// FIXME: must be a way to failed test this, thus drawback here there is no compile time checking if users specified wrong type, so it still return with garbaged value
	//typename std::enable_if_t<std::is_base_of_v<IWidget, Widget<T>>, Widget<T>*> Get()
	Widget<T>& Get()
	{
		auto search = m_hashMap.find(hashVal);
		if (search != m_hashMap.end())
		{
			// NOTE: dereference cost here for the convenience of using variable by value
			return static_cast<Widget<T>&>(*(search->second));
		}
		else
		{
			// FIXME: we should throw the exception here
			assert(false && "Not found such CVar");
		}
	}

private:
	// NOTE: we need to store the object by pointer (not by value, or by reference; the latter is impossible as the container needs to make reference when reference or possibly internally)
	// the main reason is we try to store polymorphic object type, and if we store it by value, then slicing will kick in to play and we will lose information of such derived type.
	std::unordered_map<HASH_TYPE, IWidget*> m_hashMap;
};

#define ASSERT_FLOATING_POINT(f, chk) assert(std::fabs(f - chk) <= 0.0001)
#define ASSERT_STRCMP(str, chk) assert((std::strcmp(str, chk) == 0))

int main()
{
	WidgetManager<int> w;
	Widget<int> orig_w_1 (10);
	Widget<double> orig_w_2 (10.5);
	Widget<const char*> orig_w_3 ("Test String");

	w.Add<1>(orig_w_1);
	w.Add<2>(orig_w_2);
	w.Add<3>(orig_w_3);

	{
		float fVal = orig_w_1;
		static_assert(std::is_same_v<decltype(fVal), float>);
		ASSERT_FLOATING_POINT(fVal, static_cast<int>(orig_w_1));
	}

	{
		float fVal = orig_w_3;
		static_assert(std::is_same_v<decltype(fVal), float>);
		ASSERT_FLOATING_POINT(fVal, 0); // use 0 as it's failed to convert
	}

	{
		const char* strVal = orig_w_3;
		static_assert(std::is_same_v<decltype(strVal), const char*>);
		ASSERT_STRCMP(strVal, static_cast<const char*>(orig_w_3));
	}

	{
		std::string str = orig_w_3;
		ASSERT_STRCMP(str.c_str(), static_cast<const char*>(orig_w_3));
	}

	// FIXME: by no mean accurate, and canot failed test this
	//assert((std::is_convertible_v<Widget<IWidget>, IWidget> == true));

	{
		auto var = w.Get<1, int>();
		assert(var.m_val == 10);
		var = 100;
		assert(var.m_val == 100);
	}

	{
		auto var = w.Get<2, double>();
		ASSERT_FLOATING_POINT(var.m_val, 10.5);
		var = 200.5;
		ASSERT_FLOATING_POINT(var.m_val, 200.5);
	}

	{
		auto var = w.Get<3, const char*>();
		ASSERT_STRCMP(var.m_val, "Test String");
		var = "New String";
		ASSERT_STRCMP(var.m_val, "New String");
	}


	return 0;
}
