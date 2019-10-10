/**
 * Inspired by VariadicLogging.cpp at https://riptutorial.com/git/example/4343/committing-on-behalf-of-someone-else.
 */
#include <iostream>

template<typename Arg>
size_t GetArgSize(const Arg& arg)
{
    return sizeof(arg);
}

inline size_t GetArgsSize()
{
    return 0;
}

template<typename Arg, typename... Args>
size_t GetArgsSize(const Arg& arg, const Args... args)
{
    return GetArgSize(arg) + GetArgsSize(args...);
}

int main()
{
    std::cout << "sizeof 'Hello, World' = " << GetArgsSize("Hello, World") << std::endl;
    std::cout << "sizeof 4 = " << GetArgsSize(4) << std::endl;
    std::cout << "sizeof static_cast<long>(10) = " << GetArgsSize(static_cast<long>(10)) << std::endl;
    std::cout << "Total = " << GetArgsSize("Hello, World", 4, static_cast<long>(10)) << std::endl;
    return 0;
}
