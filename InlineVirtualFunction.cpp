/**
 * Prove that virtual function can be inlined by compiler.
 *
 * In conclusion, Clang is best at this to be able to determine that inlining
 * is possible even with virtual function (even without inline keyword on such
 * virtual function). Instead GCC & MSVC won't inline them. Tested all at
 * optimization level 2 at which point clang will start to inline such virtual function.
 *
 * For each compiler, compile with the following to generate assembly code for
 * inspection. From there try to search for "call" (for clang, it's "callq"),
 * then we will find the answer.
 *
 * GCC:
 * g++ -std=c++17 -Wall -Wextra -pedantic -O2 -S InlineVirtualFunction.cpp
 *
 * Clang:
 * clang++ -std=c++17 -Wall -Wextra -pedantic -O2 -S InlineVirtualFunction.cpp
 *
 * MSVC:
 * cl.exe /EHsc /std:c++17 /W4 /O2 /FAs InlineVirtualFunction.cpp
 */

#include <iostream>

class Base
{
public:
	inline virtual void Foo()
	{
		std::cout << "Base::Foo()\n";
	}
};

class Derived : public Base
{
public:
	inline virtual void Foo() override
	{
		std::cout << "Derived::Foo()\n";
	}
};

int main()
{
	Base *bPtr = new Derived();
	bPtr->Foo();

	return 0;
}
