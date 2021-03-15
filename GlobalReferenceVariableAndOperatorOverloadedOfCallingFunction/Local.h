#pragma once

#include "Lib.h"

struct WidgetWrapper
{
	ValueContainer m_valContainer;

	// It is reference as we have global Widget variable declared in Lib.h.
	// We will make change of state to such global Widget variable through this variable.
	Widget& m_widget;

	void Foo() const
	{
		std::cout << "WidgetWrapper::Foo()" << std::endl;
	}

	WidgetWrapper();

	// this operator overload will make g_widget->Foo() possible
	WidgetWrapper* operator->()
	{
		return this;
	}
};
