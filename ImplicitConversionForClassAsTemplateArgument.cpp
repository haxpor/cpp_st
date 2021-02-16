/**
 * Demonstrate the use of conversion operator that we can benefit from it
 * at the time of implicit conversion later when we try to print the class we've
 * implemented.
 */
#include <iostream>
#include <cstdint>

struct InterpolatedValue
{
	InterpolatedValue(): m_ticks(0) { }
	InterpolatedValue(uint32_t ticks) { m_ticks = ticks; }

	// this conversion to float (or others) is vital to make implicit
	// conversion works and satisfy compiler when it tries to resolve what should
	// be called when we try to print it out with std::cout inside main()
	//
	// without it, it failed as compiler didn't have something to fall back to
	// to use and make a call
	operator float() const { return m_ticks / 10.0f; } // just something imaginary

	// these two overloaded operator are just enough to demonstrate our case here
	InterpolatedValue operator-(InterpolatedValue v) const
	{
		InterpolatedValue temp = *this;
		temp.m_ticks -= v.m_ticks;
		return temp;
	}

	InterpolatedValue& operator-=(InterpolatedValue v)
	{
		*this = *this - v;
		return *this;
	}

private:
	uint32_t m_ticks;
};

template <class T>
class Range
{
public:
	T start;
	T end;

	Range(T _start, T _end)
	{
		start = _start;
		end = _end;
	}

	T GetRange() const
	{
		return end - start;
	}
};

int main()
{
	Range<InterpolatedValue> range (InterpolatedValue(3200), InterpolatedValue(3300));
	std::cout << "Range: " << range.GetRange() << std::endl;
	return 0;
}
