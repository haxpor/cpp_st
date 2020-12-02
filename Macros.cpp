#include <iostream>

static int g_int = 1;
static int Hello = 5;
static int World = 10;

static float HelloWorld = 20.0f;

// #
#define M1(x, y) #x
#define M2(x, y) #y
#define M3(x, y) #x#y

// ##
#define M4(x, y) x ## y

int main()
{
	std::cout << M1(Hello, World) << std::endl;
	std::cout << M1(World, Hello) << std::endl;
	std::cout << M2(World, Hello) << std::endl;
	std::cout << M3(World, Hello) << std::endl;

	std::cout << M4(Hello, World) << std::endl;
	std::cout << M4(11231321, 99999) << std::endl;
	return 0;
}
