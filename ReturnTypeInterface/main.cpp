/**
 * Prove of concept that return type from the function interface doesn't require us to
 * make an inclusion of header file.
 *
 * Possibly think from the perspective of compiler, and whenever we call a function.
 * We cannot overload function with return type as of this matters.
 */
#include "Lib.h"
#include "Widget.h"

int main()
{
	Lib lib;
	lib.Foo().Foo();	// this should print out 1
	return 0;
}
