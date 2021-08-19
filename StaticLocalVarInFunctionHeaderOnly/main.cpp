/**
 * Prove-of-concept that static variable declared inside a function
 * will have a single instance all across shared library.
 *
 * GCC/Clang : Widget instance is the same across all shared libraries.
 * MSVC : It is different for all 3 places (executable, another library, another 2 library)
 *
 * This is due to ability in optimization of compilers, but not the standard.
 */
#include "Lib.h"
#include "another.h"
#include "another2.h"

#include <iostream>
#include <cassert>

int main()
{
	Widget* w = GetWidgetInstance();
	w->m_val = 10;

	DoSomething();	// mutate value of Widget
	DoSomething2();	// mutate value of Widget

	// Print
	PrintAddress();
	PrintAddress2();
	std::cout << "Main: " << std::addressof(*w) << "\n";
	std::cout << w->m_val << "\n";

	// validate addresses
	assert(ValidateAddress(w));
	assert(ValidateAddress2(w));

	// validate value
	assert(w->m_val == 30);

	return 0;
}
