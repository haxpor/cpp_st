#pragma once

// global scope
constexpr int g_num1 = 10;
inline constexpr int g_num2 = 20;

// namespace scope
namespace WidgetScope
{
	constexpr int g_num3 = 30;
	inline constexpr int g_num4 = 40;
}
