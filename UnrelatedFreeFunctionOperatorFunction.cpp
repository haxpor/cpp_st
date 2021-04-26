/**
 * Play around with free function, and member overloaded operator functions.
 *
 * Notice
 *  - declaration of friend overloaed operator function (doesn't accept default template argument, and need template declaration.
 *  - certain types of operators cannot be non-member
 */
#include <cassert>

struct WidgetA
{
	int val;
	WidgetA(int v):
		val(v)
	{}
};

struct WidgetB
{
	int val;
	WidgetB(int v):
		val(v)
	{}
};

template <typename T>
struct WidgetATemplated
{
	T val;
	WidgetATemplated(T v):
		val(v)
	{}
};

template <typename T>
class WidgetBTemplated
{
public:
	WidgetBTemplated(T v):
		val(v)
	{}

	T GetVal() const
	{ return val; }

	// NOTE: operator= cannot be non-member. Check at https://en.cppreference.com/w/cpp/language/operators.
	WidgetBTemplated<T>& operator=(int setTo)
	{
		val = setTo;
		return *this;
	}

	// NOTE: This is how to declare friend template function
	template <typename U>
	friend WidgetBTemplated<U>& operator+(WidgetBTemplated<U>& wb, int add);

private:
	T val;
};

inline WidgetA& operator+(WidgetA& wa, int add)
{
	wa.val += add;
	return wa;
}

inline WidgetA& operator+(WidgetA& wa, WidgetB& wb)
{
	wa.val += wb.val;
	return wa;
}

template <typename T>
inline WidgetATemplated<T>& operator+(WidgetATemplated<T>& wa, int add)
{
	wa.val += add;
	return wa;
}

template <typename T>
inline WidgetBTemplated<T>& operator+(WidgetBTemplated<T>& wb, int add)
{
	wb.val += add;
	return wb;
}

int main()
{
	WidgetA wa(0);
	auto retWa = wa + 10;

	assert(wa.val == 10);
	assert(retWa.val == 10);

	WidgetB wb(5);
	auto retWa2 = wa + wb;
	assert(wa.val == 15);
	assert(retWa2.val == 15);

	WidgetATemplated wat(2);
	auto retWat = wat + 10;
	assert(wat.val == 12);
	assert(retWat.val == 12);

	WidgetBTemplated wbt(1);
	auto retWbt = wbt + 5;
	assert(wbt.GetVal() == 6);
	assert(retWbt.GetVal() == 6);

	wbt = 9;
	assert(wbt.GetVal() == 9);
	return 0;
}
