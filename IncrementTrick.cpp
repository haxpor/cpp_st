#include <iostream>

int main()
{
    char a[] = "Hello";
    char b[] = "Babau";

    char* aPtr = a;
    char* bPtr = b;

    // due to operator precedence table
    // it will do postfix increment first, then do de-reference
    *aPtr++ = *bPtr++;
    std::cout << "a: " << a << std::endl;
    std::cout << "b: " << b << std::endl;
    std::cout << "aPtr: " << *aPtr << std::endl;
    std::cout << "bPtr: " << *bPtr << std::endl;
    return 0;
}
