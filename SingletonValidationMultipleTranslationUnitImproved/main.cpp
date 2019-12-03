/**
 * Based on top solely on SingleValidationMultipleTranslationUnit but with improvements in regards of
 *  - simpilfied singleton pattern code leading to
 *      - no more a chore to call to Singleton::AutoDestroy(), it will destroy memory automatically
 *        via stack unwinding
 *  - use #pragma once instead of header include guard
 */

#include <iostream>
#include <cassert>
#include <cstdint>
#include "Singleton.h"
#include "MyManager.h"
#include "Another.h"

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

    // also test calling its member function
    mInstance.PrintNum(10);

    // use std::uintptr_t to hold pointer type as integer type
    // such type is guaruntee to be able to hold pointer type on the platform
    assert(reinterpret_cast<std::uintptr_t>(&mInstance) == ano.getAddress());

    return 0;
}
