/**
 * Validate testing to copy a lambda (or per se functor).
 */

#include <iostream>
#include <cassert>

int main()
{
	bool sharedBool = false;
	auto lambda = [&sharedBool](int n) {
		std::cout << "n: " << n << "\n";

		// reference variable inside lambda is still modified and working properly
		sharedBool = !sharedBool;
	};

	auto copyLambda = lambda;

	// validate both lambda are not the same object
	std::cout << "Addr of lambda: " << std::addressof(lambda) << "\n";
	std::cout << "Addr of copyLambda: " << std::addressof(copyLambda) << "\n";
	static_assert(std::addressof(lambda) != std::addressof(copyLambda));

	lambda(1);
	assert(sharedBool);
	copyLambda(2);
	assert(!sharedBool);

	auto ll = []{ std::cout << "empty\n"; };
	ll();
	return 0;
}
