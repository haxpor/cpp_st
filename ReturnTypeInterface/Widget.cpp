#include "Widget.h"
#include <iostream>

Widget::Widget(int v):
	m_val(v)
{
}

void Widget::Foo() const
{
	std::cout << m_val << std::endl;
}
