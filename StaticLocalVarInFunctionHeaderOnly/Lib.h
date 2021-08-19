#pragma once

struct Widget
{
	int m_val;
};

inline Widget* GetWidgetInstance()
{
	static Widget s_widget;
	return &s_widget;
}
