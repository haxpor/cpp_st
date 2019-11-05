/**
 * Demonstrate the issue that will arise in case of having defined a global static variable
 * at header level which included by other source file (another translation unit).
 *
 * Each translation unit will see it as another copy. Thus it's not globally shared as a single instance
 * anymore.
 *
 * Note that this can be solved by defining such static variable at
 * 1. class level
 * 2. class's method level
 * 3. free function level
 */
#include <iostream>
#include "Header.h"
#include "Another.h"

int main()
{
    Another ano;

    // this will print 10
    std::cout << "staticvar = " << staticVar << std::endl;

    // this will print 20
    staticVar += 10;
    std::cout << "staticvar = " << staticVar << std::endl;

    // now as Another.cpp is in another translation unit
    // it see staticVar as defined in Header.h as another copy thus
    // this line will show 10. This is a problem of static variable defined globally at header level
    // for multiple translation unit. PS.
    //
    // PS. Header guard only prevent duplicated definition of such variable, not prevent or solve
    // this particular problem we're facing.
    std::cout << "staticvar from Another = " << ano.getStaticVarValue() << std::endl;
    return 0;
}
