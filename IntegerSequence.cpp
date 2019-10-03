/**
 * Demonstrate usage of integer sequence for template usage.
 */

#include <iostream>
#include <initializer_list>

template <int...ints>
static void printIntegerSequence()
{
    // usually need to define the type to hold initializer_list
    int list[] = {ints...};
    for (const auto& i: list)
        std::cout << i << " ";
}

int main()
{
    printIntegerSequence<1,2,3,4,5>();
    std::cout << std::endl;
    return 0;
}
