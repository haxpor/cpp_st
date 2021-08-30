/**
 * Small validation program that const callable object still adhere to const
 * object in which it cannot make changes to its data member.
 *
 * In this test, we just check which version (const or non-const) for its
 * function call operator it would be calling.
 */
#include <iostream>

struct CallableObj
{
	int val {0};

	void operator()()
	{
		std::cout << "called non-const version\n";
	}

	void operator()() const
	{
		std::cout << "called const version\n";
	}
};

int main()
{
	{
		CallableObj c;
		c();
	}
	{
		const CallableObj c;
		c();
	}
	return 0;
}
