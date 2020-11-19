#pragma once

struct IDefaultFuncs
{
	// default parameter defined for this function can be overriden by other
	// header file
	virtual void foo(int a=10)=0;	
};
