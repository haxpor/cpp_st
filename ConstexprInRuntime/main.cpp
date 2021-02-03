#include <iostream>
#include <cmath>
#include <cstdlib>
#include <ctime>

constexpr int Compute(int i)
{
	return i + 10;
}

int main()
{
	// TEST CASE SET 1
	// for non-constexpr receiving variable from calling constexpr function
	int result1 = Compute(5);
	std::cout << "result1: " << result1 << std::endl;		// just to not let it optimize code away

	// for constexpr receiving variable from calling constexpr function
	constexpr int result2 = Compute(7);
	std::cout << "result2: " << result2 << std::endl;		// same

	// TEST CASE SET 2 (not compile as Compute() requires constant variable input)
	//std::srand(std::time(nullptr));
	//int random_input = std::rand();

	//int result3 = Compute(random_input);
	//std::cout << "result3: " << result3 << std::endl;

	//constexpr int result4 = Compute(random_input);
	//std::cout << "result4: " << result4 << std::endl;

	return 0;
}
