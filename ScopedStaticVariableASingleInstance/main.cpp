/**
 * Validate that scoped local static variable inside a function across shared libraries
 * will still have one instance all across of them.
 *
 * Also see ScopedStaticVariableASingleInstanceSameTU for same translation unit.
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
