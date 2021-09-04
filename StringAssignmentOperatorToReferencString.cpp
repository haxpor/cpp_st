/**
 * Demonstrate that assigning a std::string to another std::string even though as reference type,
 * it doesn't mean such string will point to the same instance. But it copies.
 *
 * It's the same when we use 'const std::string&` type for function's argument.
 */
#include <iostream>
#include <string>
#include <cassert>
#include <memory>

std::string str1("string 1");	

void AssignString(std::string& str)
{
	str1 = str;
}

int main()
{
	std::string str2("string 2");
	AssignString(str2);

	assert(str1 == "string 2");
	// as str1 and str2 is different object
	assert(std::addressof(str1) != std::addressof(str2));	
	assert(std::addressof(*str1.data()) != std::addressof(*str2.data()));
	return 0;
}
