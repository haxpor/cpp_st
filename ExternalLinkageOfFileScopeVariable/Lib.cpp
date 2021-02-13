#include "Lib.h"
#include <iostream>

int g_externNum = 1;
static int g_internNum = 1;

void Foo()
{
	std::cout << g_externNum << std::endl;
	std::cout << g_internNum << std::endl;
}
