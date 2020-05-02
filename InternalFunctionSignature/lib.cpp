#include "lib.h"

#include <iostream>

/**
 * internally defined like this without `static` will have risk and problem later if user's code
 * also defines the same function signature in their user space. The problem is multiple definitions.
 *
 * Build the program with `make problem` to face with the compilation error.
 * But with `make` to utilize `static` solution to prevent this error.
 */
#ifdef PROBLEM
void mess_proof();
#else
static void mess_proof();
#endif

/** no need for repetitively specify `static` here again, but defined here explicitly. **/
static void mess_proof()
{
    std::cout << "Original not tampered!\n";
}

int sum_numbers(int a, int b)
{
    mess_proof();
    return a + b;
}
