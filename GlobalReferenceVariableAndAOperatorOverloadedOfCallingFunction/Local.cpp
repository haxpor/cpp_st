#include "Local.h"

WidgetWrapper::WidgetWrapper() :
	// initialize myWidget
	// after this we can change state of g_widget through myWidget
	m_widget(g_widget)
{
}
