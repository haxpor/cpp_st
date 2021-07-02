#include "lib1.h"
#include "libcommon.h"
#include <iostream>
#include <cassert>

void SLib1::RegisterAll()
{
	SCommon::RegisterValue(1);
	SCommon::RegisterValue(2);

	std::cout << "[SLib1] total: " << SCommon::s_localList.size() << std::endl;
	assert(SCommon::s_localList.size() == 2 && "local list used in lib2 should have size of 2");
}
