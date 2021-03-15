#pragma once

#include <iostream>

class ValueContainer
{
public:
	void SetValue(int v)
	{
		foo = v;
	}

	int GetValue() const
	{
		return foo;
	}

private:
	int foo;
};

struct Widget
{
	int foo;

	void Foo() const
	{
		std::cout << "Widget::Foo()" << std::endl;
	}
};

// intend to have this only one instance across the code base
extern Widget g_widget;
