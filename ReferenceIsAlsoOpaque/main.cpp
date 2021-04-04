/**
 * Demonstrate that reference type is treated as an opaque pointer such that
 * if we didn't make use of its definition e.g. calling function, then we have no
 * need to include such component's header file. See comment in WidgetHelper.h.
 *
 * Use `make` to build the program.
 */
#include "WidgetHelper.h"
#include "Widget.h"
#include <cassert>

int main()
{
	WidgetHelper helper;
	Widget widget(10);
	assert(helper.GetWidgetInfo(widget) == 10 && "This should be 10");
	return 0;
}
