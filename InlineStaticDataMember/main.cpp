/**
 * Prove of concept for inline static data member which is available since c++17
 * to not necessary have a definition but inline in declaration.
 *
 * Such list is shared across all shared libraries.
 *
 * Also see InlineStaticFreeVariable for alternative testing for local version.
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


	for (const auto& e : SCommon::s_sharedList)
	{
		std::cout << "- " << e << "\n";
	}
	std::cout << "total: " << SCommon::s_sharedList.size() << std::endl;
	assert(SCommon::s_sharedList.size() == 5 && "shared list should have size of 5");
	return 0;
}
