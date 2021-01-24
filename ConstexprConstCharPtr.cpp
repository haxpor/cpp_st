/**
 * Demonstrate that
 * constexpr const char*
 *
 * is the same or different to
 *
 * constexpr char*
 *
 * So in conclusion, it's technically the same although declaring as `constexpr const ...` is the most ideal
 */

#include <cstring>
#include <cassert>

int main()
{
	constexpr const char* kStrDecl1 = "text";
	constexpr const char* kStrDecl2 = "text2";
	// even use this instead, it is implicitly `const`
	//constexpr const char* kStrDecl2 = "text2";

	// these shows that `constexpr const char* ...` declare compile time string
	// although we didn't opt-in to use std::strcmp as provided by GCC as built-in function for compile time checking in this case
	static_assert(kStrDecl1[0] == 't' && kStrDecl1[1] == 'e' && kStrDecl1[2] == 'x' && kStrDecl1[3] == 't', "");
	static_assert(kStrDecl2[0] == 't' && kStrDecl2[1] == 'e' && kStrDecl2[2] == 'x' && kStrDecl2[3] == 't' && kStrDecl2[4] == '2', "");

	constexpr const char* myString1 = kStrDecl1;
	// the following commented line would be possible at least on GCC but not on MSVC because
	// strcmp is builtin function that GCC can help to evaluate the line in compile time.
	//static_assert(std::strcmp(myString1, kStrDecl1) == 0, "");
	
	// compiler error if uncommented due to cannot convert const to non-const
	//constexpr char* myString2 = kStrDecl1;
	
	// if this line is uncommented, it will be compiler error as we cannot change read-only variable myString2
	// so it's implicitly `const` if we declare `constexpr`. Thus `constexpr const` will help compiler know exact type
	// of char pointer.
	//myString2 = kStrDecl2;

	return 0;
}
