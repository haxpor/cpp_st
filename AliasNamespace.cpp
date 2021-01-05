/**
 * Demonstrate aliased namespace using `using` to shorten the name in usage.
 */
#include <iostream>

namespace A
{

struct FuncsHelper
{
	static void foo(int n)
	{
		std::cout << "foo(" << n << ") called\n";
	}
};

// this line will shorten the namespace usage
using Helper = FuncsHelper;

};

int main()
{
	// call via non-aliased name
	A::FuncsHelper::foo(10);
	// call via aliased name
	A::Helper::foo(10);
	return 0;
}
