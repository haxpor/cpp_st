#pragma once

struct Widget
{
	int val {0};
};

struct CommonLib
{
	// implemented as inline header
	static Widget* GetWidgetInstance()
	{
		static Widget s_widget;
		return &s_widget;
	}
};
