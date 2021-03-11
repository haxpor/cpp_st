#include <iostream>
#include "Lib.h"

namespace Widget
{
	static void Foo()
	{
		std::cout << "Widget:Foo()" << std::endl;
	}
};

int main()
{
	Widget::Foo();
	Widget2::Foo();
	return 0;
}
