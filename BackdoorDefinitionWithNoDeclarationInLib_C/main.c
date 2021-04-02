/**
 * C version for BackdoorDefinitionWithNoDeclarationInLib
 *
 * In gcc (literally a compiler binary name for C), it will complain as follows as *warning* not error
 * unless we opt-in to include -Wimplicit-function-declaration.
 *
 * main.c: In function ‘main’:
 * main.c:5:2: warning: implicit declaration of function ‘Foo’ [-Wimplicit-function-declaration]
 *     5 |  Foo();
 *           |  ^~~
 *
 * See C++ version in BackdoorDefinitionWithNoDeclarationInLib for effect of g++ compiler.
 */
#include "Lib.h"

int main()
{
	Foo();
	return 0;
}
