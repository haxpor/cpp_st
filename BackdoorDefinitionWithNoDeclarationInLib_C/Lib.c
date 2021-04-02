#include "Lib.h"

#include <stdio.h>

// But we have defined Foo(), so this will exist inside object files.
// Just that to use it, you have to declare such function in your scope first.
void Foo()
{
	printf("Hello Foo() from Lib\n");
}
