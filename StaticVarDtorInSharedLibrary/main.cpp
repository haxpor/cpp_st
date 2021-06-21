/**
 * Demonstration for destruction (dtor function called) for static variable
 * declared and defined in a shared library.
 * It would actually show what would happen compared to the case if you
 * declared and defined static variables within the same binary (main program
 * in this case) in which it won't show you anything, even via gdb debugger to
 * set a breakpoint at dtor line of such static variable won't make a cut.
 *
 * I suspect that because static variables will be destroyed all *after* the
 * program (should say "binary" from now) has been destroyed.
 *
 * So if we separate those binary(s), then we can witness what's happening.
 *
 * This means if you try to detect destruction of static variable(s) within the
 * same binary, you won't be able to do so. You have to be on different binary
 * (in this case main program) which links with such binary as your binary is
 * not destroyed yet.
 *
 * Note: if you have more information about this to add, feel free to make PR.
 */
#include "libdummy.h"

int main()
{
	std::cout << Wrapper::s_widget.val << "\n";
	std::cout << "prior to end of main()\n";
	return 0;
}
