#include "lib2.h"
#include "commonlib.h"
#include <iostream>

void Lib2::Increment()
{
	++(CommonLib::GetWidgetInstance()->val);
}

void Lib2::Print()
{
	std::cout << CommonLib::GetWidgetInstance()->val << std::endl;
}
