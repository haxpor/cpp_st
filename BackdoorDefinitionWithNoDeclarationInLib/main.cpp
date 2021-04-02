/**
 * C++ version (for C version, see BackdoorDefinitionWithNoDeclarationInLib_C)
 *
 * g++ prevents the (initial) headache but not fully solve as we still can declare the function ourselves
 * outside of the library's physical realm of source files; let's say we don't have access to source files.
 *
 * By declaring such leaked definition in object file of such function, we can gain access to use it,
 * provided that library author isn't careful enough.
 */
#include "Lib.h"

// By default function declaration will have 'extern'.
//
/*extern*/ void Foo();

int main()
{
	Foo();
	return 0;
}
