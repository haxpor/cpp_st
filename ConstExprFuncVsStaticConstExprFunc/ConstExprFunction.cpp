#include <iostream>

// not really intend for inline so it's up to compiler
// computation happens at compile time if all arguments are known at compile time
constexpr int Compute(int a, int b) {
	return a * b + 5;
}

int main()
{
	constexpr int myNum = Compute(5, 10);
	std::cout << myNum << std::endl;
	return 0;
}
