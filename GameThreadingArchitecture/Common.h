#pragma once

#include "MathUtil.h"

#include <iostream>
#include <cstdarg>
#include <atomic>
#include <cstring>

// maximum number of circles that can be in entire game
#define MAX_CIRCLES 50

static const unsigned int RED = MathUtil::makeColorARGB(255, 0, 0, 255);
static const unsigned int GREEN = MathUtil::makeColorARGB(0, 255, 0, 255);
static const unsigned int BLUE = MathUtil::makeColorARGB(0, 0, 255, 255);
static const unsigned int WHITE = MathUtil::makeColorARGB(255, 255, 255, 255);

class Logger
{
public:
    enum class TextColor
    {
        WHITE,
        RED,
        GREEN,
        BLUE,
        MAGENTA,
        CYAN,
        YELLOW
    };

    static const int MAX_BUFFER_SIZE = 1024;
    
public:
    inline static void Log(const char* fmt, ...)
    {
        std::va_list args;
        va_start(args, fmt);
        std::vprintf(fmt, args);
        va_end(args);
        std::fflush(stdout);
    }

    template <TextColor TC = TextColor::WHITE>
    inline static void LogA(const char* fmt, ...)
    {
        // this also synchronize access to shared buffer to print out string `buffer`
        while (lock.test_and_set(std::memory_order_acquire))
            ;

        int fg;

        switch (TC)
        {
        case TextColor::WHITE: fg = 37; break;
        case TextColor::RED: fg = 31; break;
        case TextColor::GREEN: fg = 32; break;
        case TextColor::BLUE: fg = 34; break;
        case TextColor::MAGENTA: fg = 35; break;
        case TextColor::CYAN: fg = 36; break;
        case TextColor::YELLOW: fg = 33; break;

        }

        // modify fmt string
        int bwritten = std::snprintf(fmtBuffer, sizeof(fmtBuffer), "\033[1;%dm", fg);
        if (bwritten < 0) return;
        // copy original fmt not included \n
        std::strncpy(fmtBuffer + bwritten, fmt, strlen(fmt) - 1);
        std::snprintf(fmtBuffer + bwritten + strlen(fmt) - 1, sizeof(fmtBuffer) - (bwritten+strlen(fmt)), "\033[0m\n");

        std::va_list args;
        va_start(args, fmt);
        std::vprintf(fmtBuffer, args);
        va_end(args);
        std::fflush(stdout);

        lock.clear();
    }

    inline static void LogA(const char* fmt, ...)
    {
        while (lock.test_and_set(std::memory_order_acquire))
            ;

        std::va_list args;
        va_start(args, fmt);
        std::vprintf(fmt, args);
        va_end(args);
        std::fflush(stdout);

        lock.clear();
    }

private:
    static std::atomic_flag lock;
    static char fmtBuffer[MAX_BUFFER_SIZE];
};
