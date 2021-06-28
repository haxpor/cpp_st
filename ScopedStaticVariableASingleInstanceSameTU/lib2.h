#pragma once

#include "commonlib.h"
#include <iostream>

struct Lib2
{
	void Increment()
	{
		++(CommonLib::GetWidgetInstance()->val);
	}

	void Print()
	{
		std::cout << CommonLib::GetWidgetInstance()->val << std::endl;
	}
};
