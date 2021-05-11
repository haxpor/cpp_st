/**
 * PoC that `extern` doesn't need a complete type at that moment.
 * See Lib.h which forward declared a type; which in turn used as `extern` declaration.
 * It doesn't need a complete type at that moment (that translation unit).
 */
#include "Lib.h"
#include "Type.h"
#include <cassert>

int main()
{
	assert(g_widget.m_val == 2);
	return 0;
}
