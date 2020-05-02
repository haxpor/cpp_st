#include "lib.h"
#include "another_tu.h"
#include <iostream>

int main()
{
    increment_variable();
    increment_variable();
    std::cout << get_variable() << '\n';

    all_in_one();
    return 0;
}
