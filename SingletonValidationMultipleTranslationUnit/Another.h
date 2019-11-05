#ifndef ANOTHER_H_
#define ANOTHER_H_

#include <cstdint>
#include "Singleton.h"
#include "MyManager.h"

class Another
{
public:
    void printAddress() const;
    std::uintptr_t getAddress() const;
};

#endif
