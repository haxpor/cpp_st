/**
 * Demonstrate to use static inline function to use it within its translation unit only.
 * Main purpose is to create a shared library (libinline.so) by following commands
 *  - g++ -Wall -c -fPIC Inline.cpp -o Inline.o
 *  - g++ -o libinline.so --shared Inline.o
 *
 *  now we will get libinline.so
 *
 *  You can inspect symbol tables (global table, and dynamic table for linking) via
 *  - nm -C libinline.so (for global table, notice "t" and "T")
 *  - nm -CD libinline.so (for dynamnic table for linking)
 *
 *  A great walkthrough on this can be read from https://stackoverflow.com/a/52742992/571227
 *  for more information to hide certain dynamic function symbol, or all prior to compilation.
 *  By using -fvisibility=hidden to hide all dynamic function symbols, or __attribute__((visiblity("...."))) in
 *  front of function signature to achieve the effect of hiding all, hiding only one but others, etc.
 */
#include <iostream>
#include "Inline.h"

int main()
{
    // if uncomment this line, compilation will be error as FixedNumber() is not there in global symbol table
    // it's only used inside Inline library only
    //std::cout << FixedNumber(1) << std::endl;
    
    // this will works normally
    std::cout << NormalFunc(2) << std::endl;
    return 0;
}
