/**
 * Bringing in virtual keyword will affect such struct/class to create vtable
 * thus bloat the size if we dont intend to have bigger size of struct/class at the end too soon.
 *
 * If such struct/class is designed in a way that is not encouraged users to inherit from it,
 * then we shall leave virtual destructor without specifying any, unless we want to enforce
 * "final" marking to such struct/class to explicitly signify such intent.
 *
 * Compile normally.
 */
#include <iostream>

class Foo0
{
    ~Foo0() {};
};

class Foo1
{
    virtual ~Foo1() {}; 
};

int main()
{
    std::cout << sizeof(Foo0) << std::endl;	// 1 bytes (a structure shall have at least 1 byte existing)
    std::cout << sizeof(Foo1) << std::endl;	// 8 (for 64-bit) due to vtable created
    return 0;
}
