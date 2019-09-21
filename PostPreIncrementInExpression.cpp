/**
 * Demonstrate the resultant value of post/pre-incremented value inside an expression.
 */
#include <iostream>

int main()
{
    int i = 5;
    // i is still 5, but printed 4 as result
    std::cout << ((i++)-1) << std::endl;
    // i is now 6 (effect from i++)
    std::cout << i << std::endl;

    // i is 6
    std::cout << ((++i)-1) << std::endl;
    std::cout << i << std::endl;
    return 0;
}   
