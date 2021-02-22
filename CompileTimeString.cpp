/**
 * Attempt to implement a simple compile time string.
 * Note: It has a fixed memory address, so it can be passed around without worry.
 *
 * The string type will always have maximum space of 32 + 1 null-terminated bytes although the assigned string
 * has length less than that. To solve the problem of no-fixed size, and allocate to what is actually
 * needed, we need recursive template-based solution which usually requires exploding the string into
 * characters.
 *
 * Anyway the solution we have below has less code, more straightforward, and easier to implement.
 */

#include <iostream>
#include <cstring>

template <char... CHRS>
struct CompileTimeStringT
{
	static constexpr unsigned length = sizeof...(CHRS) + 1;

	// better to use stack data member (note: "static constexpr" here implies "inline")
	// instead of using static class's data member as it menas it will have lifetime of application
	// thus we won't bloat the binary size as well as only bound the lifetime usage during its need
	static constexpr const char strVal[sizeof...(CHRS)+1] = {CHRS..., '\0'};
};

#define EXPLODE_STR_1(STR, I) (I < sizeof(STR) ? STR[I] : '\0')
#define EXPLODE_STR_2(STR, I) EXPLODE_STR_1(STR, I), EXPLODE_STR_1(STR, I+1)
#define EXPLODE_STR_4(STR, I) EXPLODE_STR_2(STR, I), EXPLODE_STR_2(STR, I+2)
#define EXPLODE_STR_8(STR, I) EXPLODE_STR_4(STR, I), EXPLODE_STR_4(STR, I+4)
#define EXPLODE_STR_16(STR, I) EXPLODE_STR_8(STR, I), EXPLODE_STR_8(STR, I+8)
#define EXPLODE_STR_32(STR, I) EXPLODE_STR_16(STR, I), EXPLODE_STR_16(STR, I+16)

// maximum string length supported is 32 characters not include null-terminated character
// that's why we need one more byte at strVal definition
#define CSTRING32(str) CompileTimeStringT<EXPLODE_STR_32(str, 0)>

int main()
{
	// use as a type
	using MyStringType = CSTRING32("Hello world");
	std::cout << MyStringType::strVal << '\n';
	std::cout << "strlen: " << strlen(MyStringType::strVal) << '\n';
	std::cout << "sizeof: " << sizeof(MyStringType::strVal) << '\n';

	// use as a variable
	auto myString = CSTRING32("Hello world"){};
	std::cout << myString.strVal << '\n';
	std::cout << "strlen: " << strlen(myString.strVal) << '\n';
	std::cout << "sizeof: " << sizeof(myString.strVal) << '\n';

	static_assert(std::strcmp(MyStringType::strVal, myString.strVal) == 0, "both string must be equal");
	static_assert(strlen(MyStringType::strVal) == strlen(myString.strVal) && strlen(myString.strVal) == strlen("Hello world"), "strlen must be correct value");
	static_assert(sizeof(MyStringType::strVal) == sizeof(myString.strVal) && sizeof(myString.strVal) == MyStringType::length, "sizeof must be correct value");
	return 0;
}
