/**
 * Demonstrate usage of std::alignment_of (which in turn makes use of alignof operator)
 */
#include <iostream>
#include <type_traits>

struct Empty {};
struct NotEmpty
{
    int a;
    double b;
};

int main()
{
    std::cout << std::alignment_of<int>::value << std::endl;
    // alternative syntax
    std::cout << std::alignment_of<int>() << std::endl;

    std::cout << std::alignment_of<Empty>::value << std::endl;
    std::cout << std::alignment_of<NotEmpty>::value << std::endl;

    return 0;
}
