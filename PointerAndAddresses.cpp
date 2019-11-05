/**
 * Demonstrate validation between result from std::addressof whether which one aligned with its result
 * from using raw pointer.
 *
 * Result
 *  - std::addressof will give result of address of input variable itself.
 *
 * Reference
 *  - very good link to see the summary of 3 types printing something from pointer https://stackoverflow.com/a/33696999/571227
 */
#include <iostream>
#include <memory>

int main()
{
    int a = 10;
    int* ptr = &a;
    std::cout << "Address of pointer pointed to = " << ptr << std::endl;
    std::cout << "Value of pointer pointed to = " << *ptr << std::endl;
    std::cout << "Address of pointer itself = " << &ptr << std::endl;

    // this is the same as printing address of ptr itself
    std::cout << "std::addressof(ptr) = " << std::addressof(ptr) << std::endl;
    // this is the same as printing address of *ptr
    std::cout << "std::addressof(*ptr) = " << std::addressof(*ptr) << std::endl;
    return 0;
}
