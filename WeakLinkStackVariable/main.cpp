#include "WeakSymbol.h"
#include "Lib1.h"
#include "Lib2.h"
#include <iostream>
#include <cassert>

// define weak symbol, compiler still choose its locally defined one in Lib1 component
WEAK_SYMBOL int g_var1 = 6;

// define non-weak symbol (strong), so it should use this value
#if defined(__GNUC__)
StructVar g_structVar2(5);
#elif defined(_MSC_VER)
// NOTE: msvc compiler will shout out error of redifinition if we omit WEAK_SYMBOL here, so if such variable intended to be weak symbol, then always mark it as such for all its definitions
WEAK_SYMBOL StructVar g_structVar2(5);
#endif

WEAK_SYMBOL StructVar g_structVar4(6);

int main()
{
	assert(g_var1 == 1);
#if defined(__GNUC__)
	assert(g_structVar2.val == 5);
#elif defined(_MSC_VER)
	assert(g_structVar2.val == 2);
#endif
	assert(g_var2 == 2);
	assert(g_structVar3.val == -1);
	assert(g_structVar4.val == 4);
	return 0;
}
