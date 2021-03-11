#include <iostream>

// we need to forward declare the function defined inside the namespace before actual use
// or else compiler will shout out error.
// 
// If we don't want to forward declare like this, we need to move the definition of such Detail namespace
// up here instead.
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
