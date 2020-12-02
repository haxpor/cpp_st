#include <iostream>

struct Widget
{
	// more verbose output
	void foo()
	{
#ifdef _MSC_VER
		std::cout << __FUNCSIG__ << std::endl;
#elif defined(__GNUC__) || defined(__GNUG__)
		std::cout << __FUNCTION__ << std::endl;
#elif __clang
		std::cout << __FUNCTION__ << std::endl;
#endif
	}

	// better printing output
	void bar()
	{
#if defined(__GNUC__) || defined(__GNUG__)
		std::cout << __PRETTY_FUNCTION__ << std::endl;
#elif defined(__clang) || defined(_MSC_VER)
		std::cout << __FUNCTION__ << std::endl;
#endif
	}
};

int main()
{
	Widget w;
	w.foo();
	w.bar();
	return 0;
}
