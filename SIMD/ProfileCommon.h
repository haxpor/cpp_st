#pragma once

#include <chrono>

struct Profile
{
    static std::chrono::steady_clock::time_point gProfile_startTime;

    inline static void Start()
    {
        gProfile_startTime = std::chrono::steady_clock::now();
    }

    inline static void EndAndPrint()
    {
        std::cout << " execution elapsed " << std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - gProfile_startTime).count() << "ms" << std::endl;
    }

    // std::chrono::microseconds has type long int on 64-bit Linux (Ubuntu 18.04)
    // return in microseconds integer
    inline static long int End()
    {
        return std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - gProfile_startTime).count();
    }
};

std::chrono::steady_clock::time_point Profile::gProfile_startTime;
