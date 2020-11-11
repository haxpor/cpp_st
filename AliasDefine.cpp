/**
 * Compile this program by providing the definition of ALIAS_MYLOG
 * so you should not see "test" output at the console.
 *
 * Otherwise if compile without ALIAS_MYLOG definition supplied, then you should see
 * "test" output.
 */
#include <iostream>

#ifdef ALIAS_MYLOG
#define MyLog(...) ((void)0)
#else
void MyLog(const char* text)
{
    std::cout << text << std::endl;
}
#endif

int main()
{
    MyLog("test");
    return 0;
}
