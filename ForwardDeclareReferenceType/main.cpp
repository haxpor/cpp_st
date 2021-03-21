/**
 * Demo for forward declaration of reference type.
 * It is also possible same as we did with forward declare pointer type.
 * Reference type is a pointer concept behind the scene.
 *
 * Note:
 * It is difficult to forward declare a typedef type.
 * Take dependency extractor/analyzer package implemented by John Lakos (https://www.informit.com/store/large-scale-c-plus-plus-software-design-9780201633627 at Downloads section) for an example. The source code uses forward declare "ostream". But be aware that it is compiled with a different compiler.
 *
 * I tried to do the same thing with std::ostream, but it's rather complicated. See https://stackoverflow.com/questions/804894/forward-declaration-of-a-typedef-in-c for possible solution.
 * At the end, I believe it's not worth it to do so, but at some point I will check if newer standard or whether there is a certain way to do it in easier way.
 */
#include "Lib.h"
#include "Lib2.h"

int main()
{
	Lib2Widget w { 10.4 };
	PrintLib2Widget(w);
	return 0;
}
