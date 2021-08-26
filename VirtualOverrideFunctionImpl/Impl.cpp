#include "Hdr.h"

#include <iostream>

// We cannot define it like this. It will result in redefinition.
/**
class Widget
{
public:
	virtual void Foo() override
	{
		std::cout << "Foo()\n";
	}
};
**/

// Do this instead
// Note: "virtual", and "override" are not allowed outside of a class definition
//       so no need to add them here rather than only in declaration that is
//       outside of a class definition.
void Widget::Foo()
{
	std::cout << "Foo()\n";
}
