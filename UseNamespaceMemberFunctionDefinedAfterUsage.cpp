#include <iostream>

// we need to forward declare the function defined inside the namespace before actual use
// or else compiler will shout out error.
namespace Detail { static void Foo(); }

int main()
{
	Detail::Foo();
	return 0;
}

namespace Detail
{
	static void Foo()
	{
		std::cout << "Foo()" << std::endl;
	}
}
