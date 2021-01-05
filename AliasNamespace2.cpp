/**
 * Just a simple prove of concept of using `using` to alias struct inside namespace scope.
 */
#include <iostream>

namespace A
{
	struct Util
	{
		static void foo()
		{
			std::cout << "foo()\n";
		}
	};
};

using MyUtil = A::Util;

int main()
{
	// there is no need for A::MyUtil anymore
	MyUtil::foo();
	return 0;
}
