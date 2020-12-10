#include "source1.h"
#include "source2.h"
#include <iostream>

int main()
{
	Widget1 w1;
	Widget2 w2;

	std::cout << "w1: " << w1.foo() << std::endl;
	std::cout << "w2: " << w2.foo() << std::endl;

	return 0;
}
