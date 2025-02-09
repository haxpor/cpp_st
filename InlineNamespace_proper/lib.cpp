#include "lib.h"

#include <iostream>

#ifndef V2
void lib::foo()
{
	std::cout << "lib::foo" << std::endl;
}
#elif defined(V2)
void lib::v2::foo()
{
	std::cout << "lib:v2::foo" << std::endl;
}
#endif
