#include "ConsumerHeader.h"

// at this line we cannot do
// "void Consumer::foo(int a=20)" for same value
// or
// "void Consumer::foo(int a=30)" for different value
void Consumer::foo(int a)
{
	std::cout << "a: " << a << std::endl;
}
