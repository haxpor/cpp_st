#include <iostream>
#include "defs.h"

/**
 * Misc test of having non-compile time function
 * to initialize global variable.
 */
int test(int v)
{
	return 5 * v;
}
// This is possible
static int myInt = test(12);

int main()
{
	std::cout << "g_myName: " << g_myName << std::endl;
	std::cout << myInt << std::endl;
	return 0;
}
