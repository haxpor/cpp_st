/**
 * Demonstrate that the default parameter of function even if it's definition
 * if we can make sure that it exists at the time of the call, then it can be used.
 *
 * It won't be expanded or evaluated just yet, until the runtime.
 *
 * If we rely on the existent definition of eDefaultN then we have to make sure that order of header
 * inclusion is right, and we might possibly have to check if it's defined already via #ifdef / #ifndef
 * in order to overwrite definition again or else. So be considerated to use this approach.
 */
#include <iostream>
#include "module.h"					// if move this line to be after the below included line, then it won't work
#include "funcConsumer.h"

int main()
{
	Widget w;
	w.foo();
	return 0;
}
