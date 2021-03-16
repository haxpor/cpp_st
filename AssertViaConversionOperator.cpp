/**
 * Add demo of assertion on a stack variable which implements the conversion operator.
 * It is usable.
 */
#include <iostream>
#include <cassert>

struct Widget
{
	operator Widget*()
	{
		std::cout << "Conversion to pointer of itself" << std::endl;
		return this;
	}
	
	// if we uncomment these lines, compiler will choose to use this instead and it's closer to what we need
	// as boolean operation for checking in assert()
	// NOTE: Uncomment these lines to see the effect as compiler will choose this implementation instead
	//operator bool()
	//{
	//	std::cout << "Conversion to bool" << std::endl;
	//	return true;
	//}
};

int main()
{
	Widget w;
	assert(w);	// this will trigger conversion operator of Widget, as it's stack variable it will always have address in that scope
	return 0;
}
