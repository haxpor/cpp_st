/**
 * Prove of concept for Effective Modern C++ Item 6
 */
#include <vector>
#include <cassert>
#include <iostream>
#include <cstring>

bool cStrEqual(const char* a, const char* b)
{
    return std::strcmp(a, b) == 0;
}

int main()
{
    std::vector<bool> vbool = { true, false, true };

    // intention to have bool, so explicit use non-auto is better for this case of std::vector
    bool b = vbool[1];
    // it is "bool" for MSVC
    // it is "b" for gcc
    std::cout << typeid(b).name() << std::endl;

    auto bAuto = vbool[1];
    // it is "class std::_Vb_reference<struct std::_Wrap_alloc<class std::allocator<unsigned int> > >" for MSVC
    // it is "St14_Bit_reference" for gcc
    std::cout << typeid(bAuto).name() << std::endl;
    // it must not be bool type
    assert(!cStrEqual(typeid(bAuto).name(), "b") && !cStrEqual(typeid(bAuto).name(), "bool");

    return 0;
}
