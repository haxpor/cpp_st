#pragma once

#include <vector>

struct SCommon
{
	// NOTE: provide shared list for all shared libraries
	// inline static as data member is available since c++17
	inline static std::vector<int> s_sharedList;

	static void RegisterValue(int v)
	{
		s_sharedList.push_back(v);
	}
};
