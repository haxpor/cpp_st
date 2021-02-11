#include "Consumer2.h"
#include <iostream>
#include <memory>

void Consumer2::Consumer2_PrintMemoryAddress()
{
	std::cout << "--- Consumer 2\n";
	std::cout << "g_num1 address: " << std::addressof(g_num1) << '\n';
	std::cout << "g_num2 address: " << std::addressof(g_num2) << '\n';
	std::cout << "g_num3 address: " << std::addressof(WidgetScope::g_num3) << '\n';
	std::cout << "g_num4 address: " << std::addressof(WidgetScope::g_num4) << '\n';
}
