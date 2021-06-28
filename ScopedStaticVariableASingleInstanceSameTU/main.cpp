/**
 * Validate that scoped static variable inside function in the same translation unit (TU)
 * will have only one instance.
 */
#include "lib.h"
#include "lib2.h"

#include <cassert>

int main()
{
	Lib lib1;
	Lib2 lib2;
	lib1.Increment();
	lib1.Increment();
	lib1.Increment();
	lib2.Increment();

	lib1.Print();
	lib2.Print();
	return 0;
}
