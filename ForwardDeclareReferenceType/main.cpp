/**
 * Demo for forward declaration of reference type.
 * It is also possible same as we did with forward declare pointer type.
 * Reference type is a pointer concept behind the scene.
 */
#include "Lib.h"
#include "Lib2.h"

int main()
{
	Lib2Widget w { 10.4 };
	PrintLib2Widget(w);
	return 0;
}
