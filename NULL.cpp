#include <iostream>
#include <type_traits>

int main()
{
    // with GCC: output is "l" (long via c++filt)
    // with MSVC: output is "int"
    std::cout << typeid(NULL).name() << std::endl;
#if defined(__GNUC__)
    static_assert(std::is_same<decltype(NULL), long>::value, "NULL should be long");
#elif defined(_MSC_VER)
    static_assert(std::is_same<decltype(NULL), int>::value, "NULL should be int");
#endif

    // GCC: output is "Dn" (or decltype(nullptr) via c++filt)
    // MSVC: output is "std::nullptr_t"
    std::cout << typeid(nullptr).name() << std::endl;
    return 0;
}
