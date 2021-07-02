#include "lib2.h"
#include "libcommon.h"
#include <iostream>
#include <cassert>

void SLib2::RegisterAll()
{
	SCommon::RegisterValue(3);
	SCommon::RegisterValue(4);
	SCommon::RegisterValue(5);

	std::cout << "[SLib2] total: " << SCommon::s_localList.size() << std::endl;
	assert(SCommon::s_localList.size() == 3 && "local list used in lib1 should have size of 3");
}
