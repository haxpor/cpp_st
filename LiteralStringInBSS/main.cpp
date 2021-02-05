/**
 * When compile with default or non-optimization level with GCC (9.3) and MSVC (2019),
 * it will include all the literal string we've used in the source code.
 * But if compiled with higher optimization level, it will include only what
 * used in the program.
 *
 * But it will include what's only used in the source code in higher optimization level
 * at least tested with level 2.
 *
 * See more detail in README.md.
 */
#include <string>
#include <iostream>

static const char* GetString(int i)
{
	const char* localStringLiteral = "default string";
	if (i == 0)
		localStringLiteral = "string is 0";
	else if (i == 1)
		localStringLiteral = "string is 1";
	else
		localStringLiteral = "string is something else";

	return localStringLiteral;
}

int main()
{
	const char* receivingString = GetString(0);
	const char* receivingString2 = GetString(3);

	std::cout << receivingString << '\n';
	std::cout << receivingString2 << '\n';
	return 0;
}
