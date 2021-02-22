/**
 * Attempt to implement compile-time string type with non-fixed buffer size.
 * Compare this to CompileTimeString.cpp.
 *
 * Note:
 *
 * - EXPLODE_STR_* macros needed to convert literal string into stream of individual character
 *   to be used for template argument as it doesn't support using literal string as template argument.
 * - RecurseString function template is used to finally allocate non-fixed size to hold string, it will
 *   build up from 1 bytes and up to the target length+1 of the input string.
 *
 */
#include <iostream>
#include <cstring>

template <char... CHRS>
struct CompileTimeStringT
{
	template <char CH>
	struct Add
	{
		using result = CompileTimeStringT<CHRS..., CH>;
	};

	static constexpr const char strVal[sizeof...(CHRS)+1] = {CHRS..., '\0'};
};

template <typename STRRESULT, char... CHRS>
struct RecurseString;

template <typename STRRESULT, char CLEAD, char... CHRS_LESS>
struct RecurseString<STRRESULT, CLEAD, CHRS_LESS...>
{
	// dependent-type template argument needs "typename" in front
	// as well as adding "template" in-front of Add<>
	using front = typename STRRESULT::template Add<CLEAD>::result;
	using result = typename RecurseString<front, CHRS_LESS...>::result;
};

template <typename STRRESULT, char... CHRS>
struct RecurseString <STRRESULT, '\0', CHRS...>
{
	using result = STRRESULT;
};

template <typename STRRESULT>
struct RecurseString<STRRESULT>
{
	using result = STRRESULT;
};

#define EXPLODE_STR_1(STR, I) (I < sizeof(STR) ? STR[I] : '\0')
#define EXPLODE_STR_2(STR, I) EXPLODE_STR_1(STR, I), EXPLODE_STR_1(STR, I+1)
#define EXPLODE_STR_4(STR, I) EXPLODE_STR_2(STR, I), EXPLODE_STR_2(STR, I+2)
#define EXPLODE_STR_8(STR, I) EXPLODE_STR_4(STR, I), EXPLODE_STR_4(STR, I+4)
#define EXPLODE_STR_16(STR, I) EXPLODE_STR_8(STR, I), EXPLODE_STR_8(STR, I+8)
#define EXPLODE_STR_32(STR, I) EXPLODE_STR_16(STR, I), EXPLODE_STR_16(STR, I+16)

// character array will be built up from size 1 to the target string's length (+1 further)
#define CSTRING32(str) RecurseString<CompileTimeStringT<>, strlen(str), EXPLODE_STR_32(str, 0)>::result

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

	const char* tstring = "test string";
	std::cout << tstring << std::endl;
	return 0;
}
