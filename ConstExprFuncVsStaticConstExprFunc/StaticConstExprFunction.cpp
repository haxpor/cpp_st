#include <iostream>

// intend for inline (static constexpr) function
// computation happens at compile time, and inline
static constexpr int Compute(int a, int b) {
	return a * b + 5;
}

int main()
{
	constexpr int myNum = Compute(5, 10);
	std::cout << myNum << std::endl;
	return 0;
}
