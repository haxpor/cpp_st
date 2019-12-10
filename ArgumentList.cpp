/**
 * Demonstrate that we can directly modify the fmt string from argument list sent in from the 
 * function argument.
 *
 * [Extra]
 * To traverse into the argument list, you call va_start. But before that we can do something with it.
 * Note from va_start() that first call will return next argument after the `fmt`.
 * Each call to va_start() should be match with va_end(), and we can do it multiple times.
 */

#include <cstdarg>
#include <iostream>
#include <cstring>

inline void Log(const char* fmt, ...)
{
    std::cout << fmt << std::endl;
    std::cout << strlen(fmt) << std::endl;
}

int main()
{
    Log("Test %d", 1);
    return 0;
}
