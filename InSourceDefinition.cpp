#include <iostream>

#define DEF1

#ifdef DEF1
static int var1 = 1;
#else
static int var1 = 10;
#endif

#undef DEF1

#ifdef DEF1
static int var2 = 2;
#else
static int var2 = 20;
#endif

int main()
{
	std::cout << "var1: " << var1 << "\n";
	std::cout << "var2: " << var2 << "\n";
	return 0;
}
