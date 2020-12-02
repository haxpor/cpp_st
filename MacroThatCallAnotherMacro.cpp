#include <iostream>

// declaration of MACRO2 can be after MACRO1 as the time of expansion of such macro will be expanded
// later not now (the time of declaration)
#define MACRO1(x) MACRO2(x)
#define MACRO2(x) std::cout << x << std::endl;

int main()
{
	MACRO2("Test");
	MACRO2(1);
	return 0;
}
