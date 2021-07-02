#include "libcommon.h"

void SCommon::RegisterValue(int v)
{
	SCommon::s_localList.push_back(v);
}
