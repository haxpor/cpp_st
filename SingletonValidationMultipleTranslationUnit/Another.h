#ifndef ANOTHER_H_
#define ANOTHER_H_

#include <cstdint>
#include "Singleton.h"
#include "MyManager.h"

class Another
{
public:
    // call this method before or after other source file call Singleton<T>::GetInstance()
    // to let such Singleton exists first or not before depends on test case.
    void printAddress() const
    {
        std::cout << "Address of MyManager singleton = " << &(Singleton<MyManager>::GetInstance()) << std::endl;
    }

    std::uintptr_t getAddress() const
    {
        return reinterpret_cast<std::uintptr_t>(&(Singleton<MyManager>::GetInstance()));
    }
};

#endif
