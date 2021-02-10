/**
 * Demonstrate difference style of printing output from __func__, __FUNCTION__, and
 * __PRETTY_FUNCTION__ across all compilers MSVC, GCC, and Clang.
 */
#include <iostream>

namespace Widget::Custom
{
void Foo()
{
	std::cout << "__func__ -> " << __func__ << '\n';
	std::cout << "__FUNCTION__ -> " << __FUNCTION__ << '\n';
#ifndef _MSC_VER
	std::cout << "__PRETTY_FUNCTION__ -> " << __PRETTY_FUNCTION__ << '\n';
#endif
}
}

int main()
{
	Widget::Custom::Foo();
	return 0;
}
