#include <iostream>
#include <cassert>
#include <cstring>

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

// macros accepting name to declare and initialize variable
template <typename T>
struct Widget
{
	Widget(T val):
		m_val(val)
	{}

	T m_val;
};
#define DECLARE_TEMPL_VAR(name, type, val) Widget<type> g_##name(val)

// string argument
#define DECLARE_VAR(moduleName, name, val) int g_##moduleName##_##name = val

#define KERN_INDICATOR "Something"

int main()
{
	assert(std::strcmp(M1(Hello, World), "Hello") == 0);
	assert(std::strcmp(M1(World, Hello), "World") == 0);
	assert(std::strcmp(M2(World, Hello), "Hello") == 0);
	assert(std::strcmp(M3(World,Hello), "WorldHello") == 0);

	assert(M4(Hello, World) == HelloWorld);
	assert(M4(11231321, 99999) == 1123132199999);

	DECLARE_TEMPL_VAR(myTemplVar, int, 10);
	assert(g_myTemplVar.m_val == 10);

	DECLARE_VAR(TestModuleName, myTest, 2);
	assert(g_TestModuleName_myTest == 2);

	assert(std::strcmp(KERN_INDICATOR " concatenates with STR", "Something concatenates with STR") == 0);

	return 0;
}
