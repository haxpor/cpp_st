/**
 * Demonstrate to confirm that multiple translation unit still see static variable defined inside a
 * class's method as the same single one across all of translation units.
 *
 * Singleton.h is copied from SingletonManager example.
 *
 * Extra Note:
 *  - even pass multiple source file into a compiler at once still regarded as multiple translation unit,
 *    one for each file.
 */

#include <iostream>
#include <cassert>
#include <cstdint>
#include "Singleton.h"
#include "MyManager.h"
#include "Another.h"

auto mmsingleton = Singleton<MyManager>::AutoDestroy();

int main()
{
    Another ano;

    // get underlying singleton object wrapped by Singleton for use in the current scope
    auto& mInstance = Singleton<MyManager>::GetInstance();
    auto* mInstancePtr = &mInstance;

    // the following commented block is just a prove of concept that
    // pointer variable's address needs not to be the same across multiple translation unit
    // it's normal variable to hold memory address, but more important thing is address it points to
    //std::cout << "Address of pointer points to singleton = " << &mInstancePtr << std::endl;

    std::cout << "Address of MyManager from main.cpp = " << &mInstance << std::endl;
    ano.printAddress();

    // use std::uintptr_t to hold pointer type as integer type
    // such type is guaruntee to be able to hold pointer type on the platform
    assert(reinterpret_cast<std::uintptr_t>(&mInstance) == ano.getAddress());

    return 0;
}
