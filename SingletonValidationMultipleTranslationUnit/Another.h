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
        auto& inst = Singleton<MyManager>::GetInstance();

        // the following commented block is just a prove of concept that
        // pointer variable's address needs not to be the same across multiple translation unit
        // it's normal variable to hold memory address, but more important thing is address it points to
        //{
        //    auto* instPtr = &inst;
        //    std::cout << "Address of pointer points to singleton = " << &instPtr << std::endl;
        //}

        return reinterpret_cast<std::uintptr_t>(&inst);
    }
};

#endif
