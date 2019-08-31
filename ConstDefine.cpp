/**
 * Demonstrate `const` can be defiend after type id depending on convention used in the team.
 *
 * Anyway, I feel defining in this way is somewhat confusing, especially when combined with
 * definition of pointer variable type.
 *
 * note:
 *  - Noticed this kind of style in GLM's template struct of mat. See its function's argument.
 *  - when confused, read from right to left
 */

#include <iostream>

static int GlobalVar = 15;

void PrintValue(int const& n)
{
    std::cout << n << std::endl;
}

// most people define it like this for pointer to type id
void PrintValue(const int* const n)
{
    std::cout << *n << std::endl;
}

// less used, but also possible.
// Hint: read from right to left for any case.
void PrintValue2(int const * const n)
{
    std::cout << *n << std::endl;
}

int main()
{
    int const weird = 10;

    // it should be properly compiled with no warning, and printed as correct value
    std::cout << weird << std::endl;

    PrintValue(GlobalVar);
    PrintValue(&GlobalVar);
    PrintValue2(&GlobalVar);
    return 0;
}
