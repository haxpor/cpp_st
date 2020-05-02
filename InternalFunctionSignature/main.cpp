#include "lib.h"
#include <iostream>

void mess_proof()
{
    std::cout << "Tampered message\n";
}

int main()
{
    mess_proof();
    std::cout << sum_numbers(5, 1) << '\n';
    return 0;
}
