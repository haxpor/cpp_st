/**
 * Demonstrate the use of "private" and unimplemented function even for its
 * own class.
 *
 * Mark "private", and only declare the functions, but no definition to prevent
 * anyone to use it even itself. Otherwise, it will result in linker error.
 *
 * The cure is to also mark with "= default" to let compiler fill the implementation
 * for us by default, but it's just not what we intended to do here.
 *
 * Build:
 *
 * Normally compile, but if -DDEMON_CLASS or /DDEMON_CLASS defined then this
 * demo will produce linker error coming from usage within Widget class.
 *
 * Otherwise if no -DDEMON_CLASS or /DDEMON_CLASS supplied, then it will
 * show compile error from accessing private function(s).
 */
#include "Widget.h"

int main()
{
#if DEMON_CLASS
	Widget w1;
	Widget w2 = w1;
#else
	// when no -DDEMON_CLASS supplied at compile time, then it will produce
	// compile time error for accessing private function
	Widget w1(1);
#endif
	return 0;
}
