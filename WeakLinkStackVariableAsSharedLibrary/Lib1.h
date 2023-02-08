#pragma once
#include "WeakSymbol.h"

// declared it outside of the class scope
// use 'extern' to express that this variable will have only one definition whenever linked all components (object files) together
extern int g_var1;

// declared as weak symbol and initialize the value
// NOTE: there is no separate definition for this required, or should be done.
// NOTE2: without 'extern' is fine, just that we didn't express that g_var2 should have definition defined elsewhere when link as itself already did define as weak symbol, and compiler will use this one if we refer to it in code.
// NOTE3: actually I think involve using 'extern' as well provides better and close-nit usage of the code and it better express the usage, and the most important is you can separate declaration and definition in to separate file. Anyway, for source file that includes this header if attempts to define the same name variable again, it will be definitely redifinition. Compare this to 'extern' way.
WEAK_SYMBOL int g_var2 = 2;

struct Lib1
{
};
