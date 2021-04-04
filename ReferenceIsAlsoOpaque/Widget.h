#pragma once

struct Widget
{
	Widget(int info):
		m_info(info)
	{ }

	int GetInfo() const { return m_info; }

private:
	int m_info;
};
