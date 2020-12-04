#pragma once

const char* UtilGetName(int n)
{
	if (n == 1)
		return "one";
	else if (n == 2)
		return "two";
	else
		return "unknown";
}
