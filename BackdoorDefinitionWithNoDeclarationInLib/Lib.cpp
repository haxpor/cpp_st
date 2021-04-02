#include "Lib.h"

#include <iostream>

// But we have defined Foo(), so this will exist inside object files.
// Just that to use it, you have to declare such function in your scope first.
void Foo()
{
	std::cout << "Hello Foo() from Lib" << std::endl;
}
