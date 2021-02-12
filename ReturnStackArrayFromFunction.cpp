/**
 * For GCC, warning of -Wreturn-local-addr will be shown.
 * For Clang, warning of -Wreturn-stack-address will be shown
 *
 * Both GCC and Clang, compile with
 *
 * [g++|clang++] -std=c++17 -Wall -Wextra -pedantic <source-file>
 *
 * For MSVC, didn't even warn about it (specific C4172 warning type) from the
 * following compile options
 *
 * cl.exe /EHsc /std:c++17 /W4 <source-file>
 * cl.exe /EHsc /std:c++17 /W4 /w44172 <source-file>
 *
 * Reason:
 * If you do research, array will decay into pointer. In C, there is no passing
 * by reference, per se passing by reference is just a passing by value as it
 * passes the address instead.
 *
 * C++ inherits C, thus above remains. It's more or less like a design decision
 * to not allow passing array as return value from the function more than technical
 * reason as for other cases e.g. returning classes, compiler will do copying or
 * eliding a copy and internal array wrapped inside such class can be passed around.
 * See std::array for example that solves this problem in C++ realm contrasting
 * to normal array in C.
 *
 * In case of GetLocalString(), we allocate local_str on stack, and return it.
 * As it is array, it decays into a pointer then we return address by value.
 * Such address still points to the old memory on the stack frame which by now
 * erased by compiler as it already returned from the function. So we would likely
 * get garbage result, or nothing, or crash the program.
 *
 * In case of GetLocalString2(), we wrap array inside a class then return it.
 * Compiler might RVO, or copying the return value. Such internal array can be
 * safely returned as we validate checking at the end.
 */
#include <cstring>
#include <iostream>
#include <cassert>

// bad approach
//
const char* GetLocalString()
{
	char local_str[256];
	std::strcpy(local_str, "Local string");

	// array decays into pointer address of the first array element
	return local_str;
}

// better approach
struct ReturnWrapper
{
	char local_str[256];
};
ReturnWrapper GetLocalString2()
{
	ReturnWrapper retWrapper;
	std::strcpy(retWrapper.local_str, "Hello world");

	// wrap array inside class then return
	// compiler might decide to elide the copying, or actually copy to return it
	// from the function
	return retWrapper;
}

int main()
{
	// this line might crash, or might not, what returned could be anything
	// TODO: Uncomment to see the effect of compiler's warning above, it's little
	// risky to make it un-commented by default
	//std::cout << GetLocalString() << std::endl;

	// validate "better approach"	
	assert(std::strcmp(GetLocalString2().local_str, "Hello world") == 0 && "String content must be equal");
	return 0;
}
