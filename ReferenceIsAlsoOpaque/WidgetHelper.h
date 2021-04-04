/**
 * We have no need to explicitly include Widget.h header file although we require
 * Widget to be in GetWidgetInfo() interface as reference type is treated as
 * a normal pointer type; as well as we didn't make use any of its definition
 * e.g. calling function.
 *
 * So we just forward declare such type.
 *
 * At code syntax, it could deceive us that even a reference type would need
 * an explicit include of header, but it is not.
 */
#pragma once

struct Widget;

struct WidgetHelper
{
	int GetWidgetInfo(const Widget& widget) const;
};
