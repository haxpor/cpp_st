#include "WidgetHelper.h"

// now we will make use of Widget's definition by calling its GetInfo() function
// thus we need to include component header file here.
#include "Widget.h"

int WidgetHelper::GetWidgetInfo(const Widget& widget) const
{
	return widget.GetInfo();
}
