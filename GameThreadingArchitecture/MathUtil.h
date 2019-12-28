#pragma once

#include <cstdlib>
#include <ctime>

class MathUtil
{
public:
    // only call once
    static void init()
    {
        std::srand(time(nullptr));
    }

    static inline int randInt(int max)
    {
        return rand() % (max+1);
    }

    static inline int randInt2(int min, int max)
    {
        return rand() % (max+1-min) + min;
    }

    static inline float randFloat(float min, float max)
    {
        return static_cast<float>(rand()) / (static_cast<float>(RAND_MAX) + 1.0f) * (max+1-min) + min;
    }

    // will truncate input parameter to 8-bit then pack into unsigned int for color
    static constexpr inline unsigned int makeColorARGB(int r, int g, int b, int a)
    {
        return ((a&0xFF) << 24) | ((r&0xFF) << 16) | ((g&0xFF) << 8) | (b & 0xFF);
    }
};
