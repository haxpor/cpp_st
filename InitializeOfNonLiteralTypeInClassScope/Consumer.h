#pragma once

struct Widget
{
	int val;

	Widget(int v):
		val(v)
	{ }
};


struct Declarations
{
	// we cannot do this as Widget is not literal type
	// left here to see the compilation error
	// see main.cpp comments for detail at the top
	static Widget global_w = Widget(1);
};
