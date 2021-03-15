/**
 * Demonstrate the declaration of global reference variable which will be
 * initialized with global variable. So it allows state change through it.
 *
 * Also demonstrate operator overload of -> so we can call a member function
 * either via . (dot) or -> towards just a stack variable.
 */
#include "Local.h"
#include <cassert>

int main()
{
	g_widget.foo = 10;
	assert(g_widget.foo == 10);

	WidgetWrapper widgetWrapper;

	// achieve the same way of calling a member function
	// via either -> and .
	widgetWrapper->Foo();
	widgetWrapper.Foo();

	// access data member
	// via either -> and .
	widgetWrapper->m_widget.Foo();
	widgetWrapper.m_widget.Foo();

	// change state of global widget through m_widget
	widgetWrapper.m_widget.foo = 11;
	assert(g_widget.foo == 11);
	return 0;
}
