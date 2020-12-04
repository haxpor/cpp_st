#pragma once

#include "func.h"

struct Widget : public IWidget
{
	void foo(const char* log=UtilGetName(eDefaultN))
	{
		std::cout << log << std::endl;
	}
};
