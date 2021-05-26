/**
 * std::string has comparison operator defined against c-string
 * so we can use == to compare between the twos.
 */
#include <string>
#include <cassert>

int main()
{
	std::string str1 = "Some content";
	const char* str2 = "Some content";
	assert(str1 == str2);
	return 0;
}
