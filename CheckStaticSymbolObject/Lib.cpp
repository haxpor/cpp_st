#include <iostream>

// make sure this function only used within this TU (translation unit)
// other TU cannot make use of it. See also main.cpp.
static void StaticFunc()
{
	std::cout << "StaticFunc()" << std::endl;
}

void GlobalFunc()
{
	std::cout << "GlobalFunc()" << std::endl;
}
