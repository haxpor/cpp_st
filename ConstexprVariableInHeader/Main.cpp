#include "Lib.h"
#include <iostream>
#include <memory>

int main()
{
	std::cout <<  "g_variable: " << g_variable << '\n';
	std::cout <<  "g_variable2: " << g_variable2 << '\n';
	// if we tryto print the address of constexpr variable even if can be inlined before, it won't anymore as we need it to be allocated in memory space to get address. Just uncomment to see the effect.
	//std::cout << "Address of g_variable: " << std::addressof(g_variable) << '\n';
	//std::cout << "Address of Util::g_utilVariable: " << std::addressof(Util::g_utilVariable) << std::endl;
	return 0;
}
