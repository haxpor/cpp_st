#include <iostream>
#include <stdarg.h>
#include <cstdio>

// passing arguments from one macro to another starting from VARMACRO
#define VARMACRO(_format, ...) VARMACRO2(_format, ##__VA_ARGS__)
#define VARMACRO2(_format, ...) do { \
		/* we can send to function that doesn't accept directly va_list, but ... */ \
		handleArgs(_format, ##__VA_ARGS__); \
	} while(0)

void handleArgs(const char* format, ...)
{
	char buffer[256];
	va_list args;
	va_start(args, format);
	std::vsprintf(buffer, format, args);
	va_end(args);
	std::cout << buffer << std::endl;
}

int main()
{
	VARMACRO("%s - %s", "Best", "Hello");
	return 0;
}
