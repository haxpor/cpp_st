/**
 * A small check to ensure that locally defined symbol in another translation unit cannot be
 * utilized in different translation unit. In which also demonstrate how we can
 * conduct a conditional checking whether such function exists via weak linking.
 *
 * Use `make` to build the executable.
 * Use `make release` to build with -O2 applied in which it will remove statically declared (locally declared) function
 * namely StaticFunc() symbol from the object file. You can check via nm, objdump, or readelf, but at any rate,
 * the output and behavior of the program still stays the same.
 */
#include <cassert>

// use weak link to allow us to bypass a requirement of declaration before use in c++
// thus we have a chance within main() function scope to check if such function exists
__attribute__((weak)) extern void StaticFunc();
// for externally exported function, we don't have to involve weak linking
extern void GlobalFunc();

int main()
{
	assert(StaticFunc == nullptr && "StaticFunc function must not be usable in this translation unit");
	GlobalFunc();
	return 0;
}
