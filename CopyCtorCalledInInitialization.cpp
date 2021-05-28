/**
 * Contrived example to show that initialization of object will call copy ctor, not copy assginment operator.
 */

#include <iostream>
#include <cassert>

struct Widget
{
	Widget() = default;
	Widget(const Widget&)
	{
		std::cout << "copy ctr\n";
	}

	Widget& operator=(const Widget&)
	{
		assert(false);
		return *this;
	}
};

int main()
{
	Widget w1;
	[[maybe_unused]] Widget w2 = w1; 
	return 0;
}
