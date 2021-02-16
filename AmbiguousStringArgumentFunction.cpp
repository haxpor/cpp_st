/**
 * Demonstrate the problem from ambiguous ctor to choose from involving
 * variadic arguments of function.
 *
 * Constrast this with std::string whose ctor has (const char*, int length, <some other unrelated arguments>)
 * and no variadic arguments version at all. This is to avoid the ambiguity.
 *
 * So if you create a new customized string class (template or not) you probably
 * want to it to be confirmed with std::string, so variadic argument is out of question.
 *
 * Personally I found that a variadic arguments version is more useful especially
 * for custom string template as we user doesn't need to construct a string first
 * before calling (user-defined) Format() function to format the string. It can
 * efficiently allocate number of space for string to be used right away as well,
 * so better for non-excessed stack space.
 */
#include <iostream>

class MyString
{
public:
	MyString(const char* str, int length)
	{
		std::cout << "ctor - string + length" << std::endl;
	}

	MyString(const char* fmt, ...)
	{
		std::cout << "ctor - variadic" << std::endl;
	}
};

int main()
{
	// compiler selected the correct ctor as expected
	MyString str1("test", 5);

	// notice ambiguity caused as compiler selected the first ctor
	// this is a problem
	MyString str2("hello world %d", 2);

	// compiler selected the correct ctor as expected
	MyString str3("hello world %d %s", 1, "(additional text");
	return 0;
}
