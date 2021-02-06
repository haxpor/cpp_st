/**
 * Demonstrate that the global variables outside of main() function will be
 * initialized first.
 *
 * Code outside main function can only be declarations and definitions, in which
 * expressions are part of definitions.
 *
 * So we can receive user's input, or do something first before main() executed.
 */
#include <iostream>

// code outside of main() function will be initialized first
// but only allowed to have declarations and definitions
// in which expressions are part of definition, so we can have the following perfectly just fine.
int g_var = []() {
	std::cout << "global variable initialized first\n";

	int input;
	std::cin >> input; 
	std::cout << "user's input: " << input << '\n';
	return 1;
}();

int main()
{
	std::cout << "it's now main() function's turn\n";
	std::cout << "g_var: " << g_var << '\n';
	return 0;
}
