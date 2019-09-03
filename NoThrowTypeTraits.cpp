/**
 * Demonstrate the use of std::is_nothrow_copy_constructible<>::value
 */

#include <iostream>

class A
{
    A(const A&) {};
};

class B
{
    B() {};
};

int main()
{
    std::cout << std::boolalpha << std::is_nothrow_copy_constructible<A>::value << std::endl;
    std::cout << std::boolalpha << std::is_nothrow_copy_constructible<B>::value << std::endl;
    return 0;
}
