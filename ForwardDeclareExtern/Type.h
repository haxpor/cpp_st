#pragma once

struct Widget
{
	Widget():
		m_val(0)
	{}

	Widget(int v):
		m_val(v)
	{}

	int m_val;
};
