/**
 * Small test case of fold expression.
 * Seen as used in GCC 9 variant header file; specifically at
 * `constexpr bool __never_valueless()`.
 */
#include <cassert>

template <typename... Args>
bool IsTrue(Args... args)
{
	return (args && ...);
}

template <typename... Args>
int Sum(Args... args)
{
	return (args + ...);
}

int main()
{
	assert(IsTrue(true));
	assert(IsTrue(true, true));
	assert(IsTrue(true, true, true));
	assert(IsTrue(true, true, true, true));
	assert(!IsTrue(true, true, true, true, false));

	assert(Sum(1, 2, 3, 4, 5) == 15);
	assert(Sum(1, 2, 3, 4, -5) == 5);
	return 0;
}
