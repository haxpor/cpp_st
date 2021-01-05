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

	// style 2
	// note: use this style to maintain the fully qualified namespace up to this point
	using MyUtil = Util;
};

// style 1
// note: use this style to shorten the fully qualified namespace to just "MyUtil"
using MyUtil = A::Util;

int main()
{
	// usage of style 1
	MyUtil::foo();
	// usage of style 2
	A::MyUtil::foo();
	return 0;
}
