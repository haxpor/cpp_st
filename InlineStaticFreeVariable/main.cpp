/**
 * Prove of concept for internal linkage variable as for each shared library (a
 * single translation unit to build a shared library)
 * to have its own variable. Thus such list is not shared for all shared library.
 *
 * Look into libcommon.(h/cpp).
 */
#include <iostream>
#include <cassert>
#include "libcommon.h"
#include "lib1.h"
#include "lib2.h"

int main()
{
	SLib1::RegisterAll();
	SLib2::RegisterAll();
	for (const auto& e : SCommon::s_localList)
	{
		assert(false && "should not enter this section as s_localList in this translation unit is empty");
		std::cout << "- " << e << "\n";
	}
	std::cout << "total: " << SCommon::s_localList.size() << std::endl;
	assert(SCommon::s_localList.size() == 0 && "local list here should have empty size");
	return 0;
}
