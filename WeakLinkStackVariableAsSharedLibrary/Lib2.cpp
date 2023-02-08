#include "Lib2.h"

// even with 'extern' already declared for this variable, we can still define
// it as weak symbol to allow other components to define such variable, and no need to
// be defined from this component only. But it's not usually that much difference.
WEAK_SYMBOL StructVar g_structVar2(2);

WEAK_SYMBOL StructVar g_structVar4(4);
