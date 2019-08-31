/**
 * Demonstrate `const` can be defiend after type id depending on convention used in the team.
 *
 * Anyway, I feel defining in this way is somewhat confusing, especially when combined with
 * definition of pointer variable type.
 */

#include <iostream>

int main()
{
    int const weird = 10;

    // it should be properly compiled with no warning, and printed as correct value
    std::cout << weird << std::endl;
    return 0;
}
