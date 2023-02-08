/**
 * Demonstrate the use of static free variable defined in .cpp file that used
 * in multiple translation unit.
 *
 * As such variable is defined within .cpp file, it has internal linkage within
 * such implementation file so it maintains the value among all invocations
 * of all translation units (each translation units see the same value).
 */
#include <iostream>
#include "Another.h"
#include "Another2.h"

int main()
{
	std::cout << increment() << std::endl;
	std::cout << increment() << std::endl;
	std::cout << increment2() << std::endl;		// we should see 13

    return 0;
}
