/**
 * Demonstrate that enum class's value can be compared to one another.
 */
#include <iostream>

enum class WidgetEnum
{
	Value1 = 0,
	Value2
};

int main()
{
	WidgetEnum v1 = WidgetEnum::Value1;
	WidgetEnum v2 = WidgetEnum::Value2;
	if (v1 < v2)
		std::cout << "v1 is less than v2" << std::endl;
	if (v1 == v2)
		std::cout << "v1 is equal to v2" << std::endl;
	if (v1 > v2)
		std::cout << "v1 is greater than v2" << std::endl;

	return 0;
}
