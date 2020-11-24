#include "lib.h"

const char* GetName(unsigned int v)
{
	switch (v)
	{
		case eValue1: return "foo";
		case eValue2: return "bar";
		default:	  return "unknownw";
	}
}
