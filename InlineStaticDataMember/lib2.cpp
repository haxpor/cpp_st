#include "lib2.h"
#include "libcommon.h"
#include <iostream>

void SLib2::RegisterAll()
{
	SCommon::RegisterValue(3);
	SCommon::RegisterValue(4);
	SCommon::RegisterValue(5);

	std::cout << "[SLib2] total: " << SCommon::s_sharedList.size() << std::endl;
}
