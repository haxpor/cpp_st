#include "lib.h"
#include "commonlib.h"
#include <iostream>

void Lib::Increment()
{
	++(CommonLib::GetWidgetInstance()->val);
}

void Lib::Print()
{
	std::cout << CommonLib::GetWidgetInstance()->val << std::endl;
}
