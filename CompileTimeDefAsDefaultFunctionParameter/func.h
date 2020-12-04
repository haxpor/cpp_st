#pragma once

#include "utility.h"

struct IWidget
{
	virtual void foo(const char* log=UtilGetName(eDefaultN)) = 0;
};
