#include <iostream>

int main()
{
    // with GCC: output is "l" (long via c++filt)
    // with MSVC: output is "int"
    std::cout << typeid(NULL).name() << std::endl;
    return 0;
}
