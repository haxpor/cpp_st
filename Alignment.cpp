/**
 * Demonstrate inspection of alignment of type.
 * Read more at https://en.cppreference.com/w/cpp/language/object#Alignment.
 */

#include <iostream>
#include <type_traits>

struct S
{
    char a;
    char b;
};

struct X
{
    int n;
    char c;
};

int main()
{
    std::cout << "sizeof(S) = " << sizeof(S)
              << " alignof(S) = " << alignof(S)
              << " std::alignment_of(S) = " << std::alignment_of<S>() << "\n";
    std::cout << "sizeof(X) = " << sizeof(X)
              << " alignof(X) = " << alignof(X)
              << " std::alignment_of(X) = " << std::alignment_of<X>() << std::endl;
    return 0;
}
