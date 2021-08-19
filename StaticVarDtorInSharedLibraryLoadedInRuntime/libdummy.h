#pragma once

#include <iostream>

template <typename T>
struct Widget
{
	Widget(const char* _name, T _val):
		name(_name),
		val(_val)
	{
		std::cout << "Widget()\n";
	}

	~Widget() { std::cout << "~Widget()\n"; }

	const char* name;
	T val;
};

struct Wrapper
{
	static Widget<int> s_widget;
};

// it's important to have extern "C" to be compatible with dsym()
extern "C" void foo() { std::cout << "foo()\n"; }