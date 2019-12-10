#pragma once

#include "Common.h"

#include <vector>

enum class CircleColor
{
    RED,
    GREEN,
    BLUE,
    WHITE
};

struct Circle
{
    int x;
    int y;
    int depth;
    int r;
    unsigned int colorARGB; // only use RGB for now

    Circle(int x_, int y_, int depth_, int r_, unsigned int colorARGB_)
        : x(x_), y(y_), depth(depth_), r(r_), colorARGB(colorARGB_)
    {
    }
};

// for synchronizing between game-thread and render-thread
struct SyncObj
{
    std::atomic_flag syncBusyLock { ATOMIC_FLAG_INIT };

    // will be updated by other thread, so mark with volatile to prevent compiler to optimize
    // out resulting us in deadlock
    volatile bool completed[2] { false, false};
    volatile bool ready_and_reset {false};

    ~SyncObj()
    {
        syncBusyLock.clear();       
    }

    inline void waitForBothOnCurrentThreadAndReset()
    {
        // quickly use this to avoid printing too many lines
        static bool isPrinted = false;
        isPrinted = false;

        Logger::LogA<Logger::TextColor::RED>("[sync obj] waitForBoth\n");

        // don't use locking here with assumption that reading operation is atomic
        // and we won't get garbage or undefined value as completed array are already initially
        // set from start
        while (!completed[0] || !completed[1])
        {
            if (!isPrinted)
            {
                Logger::LogA<Logger::TextColor::RED>("[sync obj] after busywait in waitForBoth...\n");
                isPrinted = true;
            }
        } 

        Logger::LogA<Logger::TextColor::RED>("[sync obj] done waitForBoth\n");

        // reset is here to avoid a need to schedule reset after setReady() every frame
        // and to avoid involving timing which is unpredictable.
        reset();
    }

    inline void waitForOnCurrentThread(int i)
    {
        static bool isPrinted = false;
        isPrinted = false;

        // no bound check for perf, adhere to programmer's judgement and no mistake
        while (!completed[i])
        {
            if (!isPrinted)
            {
                Logger::LogA<Logger::TextColor::RED>("[sync obj] busy waiting for %d...\n", i);
                isPrinted = true;
            }
        } 
    }

    inline void waitReadyOnCurrentThread()
    {
        static bool isPrinted = false;
        isPrinted = false;

        while (!ready_and_reset)
        {
            if (!isPrinted)
            {
                Logger::LogA<Logger::TextColor::RED>("[sync obj] busy waiting ready_and_reset...\n");
                isPrinted = true;
            }
        }
    }

    inline void setReady()
    {

        while (syncBusyLock.test_and_set(std::memory_order_acquire))
            ;

        ready_and_reset = true;

        syncBusyLock.clear();
        Logger::LogA<Logger::TextColor::RED>("[sync obj] set ready_and_reset\n");
    }

    inline void setComplete(int i)
    {
        while (syncBusyLock.test_and_set(std::memory_order_acquire))
            ;

        completed[i] = true;

        syncBusyLock.clear();
        Logger::LogA<Logger::TextColor::RED>("[sync obj] set complete for %d\n", i);
    }

    inline void reset()
    {
        while (syncBusyLock.test_and_set(std::memory_order_acquire))
            ;

        completed[0] = false;
        completed[1] = false;
        ready_and_reset = false;

        syncBusyLock.clear();
        Logger::LogA<Logger::TextColor::RED>("[sync obj] reset both\n");
    }
};

struct GameState
{
    int id;
    int maxCircles;
    std::vector<Circle> circles;

    GameState(int id_, int maxCircles_)
        : id(id_)
        , maxCircles(maxCircles_)
    {
        circles.reserve(maxCircles);    
    }

    inline void reset()
    {
        // not change the capacity, just its elements
        circles.clear();
    }

    // follow best practice for defining free swap function for custom type here
    // take note on `using std::swap` as well
    //
    // implement this to make sure that any STL container can pick up and efficiently swap
    // between element of GameState type
    inline friend void swap(GameState& first, GameState& second)
    {
        using std::swap;    // for ADL
        swap(first.id, second.id);
        swap(first.maxCircles, second.maxCircles);

        // for std::vector both std::swap, and std::vector::swap are equal in performance output
        // as I tested it on https://github.com/haxpor/cpp_st/tree/master/VectorSwap with gcc
        // anyway to really make sure you can opt-in to use std::vector::swap
        first.circles.swap(second.circles);
        //swap(first.circles, second.circles);
    }
};
