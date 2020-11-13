#pragma once

#include "Consumer.h"
#include <iostream>

struct Widget
{
    int a;
    float b;

    void Print(const Consumer& c)
    {
        std::cout << c.num << std::endl;
    }
};
