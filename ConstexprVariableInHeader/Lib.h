#pragma once

// at no optimization level, g_variable won't be inline at least on GCC
// but on higher optimization level, it will be inlined
constexpr int g_variable = 100;

// at global scope, defining variable with `constexpr` has different meaning
// compared to defining it inside class scope. `constexpr` variable at global scope
// has internal linkage by default. If you mean to have it inline, thus specify `inline`. Most likely you will need this.
inline constexpr int g_variable2 = 101;

struct Util
{
	// different in meaning to global scope `constexpr`
	// This will inline even at no optimization level (at least on GCC, and MSVC).
	static constexpr int g_utilVariable = 50;
};
