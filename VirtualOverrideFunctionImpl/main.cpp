/**
 * Validate that "virtual" and "override" are not allowed outside of a class
 * definition.
 *
 * See Hdr.h, and Impl.cpp.
 */
#include "Hdr.h"

int main()
{
	Widget w;
	w.Foo();
	return 0;
}
