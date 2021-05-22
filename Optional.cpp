/**
 * Very simple test for internal study of std::optional focusing on
 * - operator bool()
 * - how it internally handles
 */
#include <optional>
#include <iostream>

int main()
{
	std::optional<int> opt1;

	// this line is due to std::optional overloads 'operator bool()'
	// internally it uses _M_is_engaged as bool for internal check whether such element
	// has value or not. It is used in various places of overloaded operators.
	if (!opt1)
	{
		std::cout << "out" << std::endl;
	}

	return 0;
}
