#include "lib1.h"
#include "libcommon.h"
#include <iostream>

void SLib1::RegisterAll()
{
	SCommon::RegisterValue(1);
	SCommon::RegisterValue(2);

	std::cout << "[SLib1] total: " << SCommon::s_sharedList.size() << std::endl;
}
