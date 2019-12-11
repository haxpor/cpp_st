#pragma once

#include "Common.h"
#include <chrono>

class Profile
{
public:
    static std::chrono::steady_clock::time_point gProfile_startTime;

    inline static void Start()
    {
        gProfile_startTime = std::chrono::steady_clock::now();
    }

    inline static void EndAndPrint()
    {
        std::cout << " execution elapsed " << std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - gProfile_startTime).count() << "ms" << std::endl;
    }

    inline static void EndAndPrintA()
    {
        LOGA(" execution elapsed %lu ms\n", std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - gProfile_startTime).count());
    }

    template <Logger::TextColor TC = Logger::TextColor::WHITE>
    inline static void EndAndPrintA(const char* prefixedTxt)
    {
        Logger::LogA<TC>("%s execution elapsed %lu ms\n", prefixedTxt, std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - gProfile_startTime).count());
    }

    inline static void EndAndPrintA(const char* prefixedTxt)
    {
        Logger::LogA("%s execution elapsed %lu ms\n", prefixedTxt, std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - gProfile_startTime).count());
    }

    // std::chrono::microseconds has type long int on 64-bit Linux (Ubuntu 18.04)
    // return in microseconds integer
    inline static long int End()
    {
        return std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - gProfile_startTime).count();
    }
};

std::chrono::steady_clock::time_point Profile::gProfile_startTime;
