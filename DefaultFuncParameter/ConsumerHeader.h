#pragma once

#include "Header.h"
#include <iostream>

struct Consumer : public IDefaultFuncs
{
	// default function parameter override what has been declared
	// at Header.h file
	// even if we do the following
	// "virtual void foo(int a) override"
	// it won't pickup 10 as default value from Header.h but no default value at
	// all.
	//
	// So default value will be picked up at whatever definition that such file
	// includes it from.
	virtual void foo(int a=20) override;
};
