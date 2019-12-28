#pragma once

#include "Common.h"

#include <vector>
#include <algorithm>

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

    inline void waitForBothOnCurrentThread()
    {
        // quickly use this to avoid printing too many lines
        static bool isPrinted = false;
        isPrinted = false;

        LOGA_RED("[sync obj] waitForBoth\n");

        for(;;)
        {
            while (syncBusyLock.test_and_set())
                ;

            if (!isPrinted)
            {
                LOGA_RED("[sync obj] busywait in waitForBoth...\n");
                isPrinted = true;
            }

            syncBusyLock.clear();

            if (completed[0] && completed[1])
                break;
        }

        LOGA_RED("[sync obj] done waitForBoth\n");
    }

    inline void waitForOnCurrentThread(int i)
    {
        static bool isPrinted = false;
        isPrinted = false;

        for(;;)
        {
            while (syncBusyLock.test_and_set())
                ;

            if (!isPrinted)
            {
                LOGA_RED("[sync obj] busy waiting for %d...\n", i);
                isPrinted = true;
            }

            syncBusyLock.clear();

            if (completed[i])
                break;
        }
        LOGA_RED("[sync obj] done waitFor %d\n", i);
    }

    inline void waitReadyOnCurrentThread()
    {
        static bool isPrinted = false;
        isPrinted = false;

        for(;;)
        {
            while (syncBusyLock.test_and_set())
                ;

            if (!isPrinted)
            {
                LOGA_RED("[sync obj] busy waiting ready...\n");
                isPrinted = true;
            }

            syncBusyLock.clear();

            if (ready_and_reset)
                break;
        }
        LOGA_RED("[sync obj] done waiting ready\n");
    }

    inline void setReadyAndResetAllComplete()
    {

        while (syncBusyLock.test_and_set())
            ;

        completed[0] = false;
        completed[1] = false;
        ready_and_reset = true;

        syncBusyLock.clear();
        LOGA_RED("[sync obj] set ready (and reset complete flags)\n");
    }

    inline void setComplete(int i)
    {
        while (syncBusyLock.test_and_set())
            ;

        completed[i] = true;

        syncBusyLock.clear();
        LOGA_RED("[sync obj] set complete for %d\n", i);
    }

    inline void reset()
    {
        while (syncBusyLock.test_and_set())
            ;

        completed[0] = false;
        completed[1] = false;
        ready_and_reset = false;

        syncBusyLock.clear();
        LOGA_RED("[sync obj] reset both\n");
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
