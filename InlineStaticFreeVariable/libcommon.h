#pragma once

#include <vector>

namespace SCommon
{
	// NOTE: provide a local list for each shared library to use
	inline static std::vector<int> s_localList;

	static void RegisterValue(int v)
	{
		s_localList.push_back(v);
	}
}
