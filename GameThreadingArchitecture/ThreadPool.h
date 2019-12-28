#pragma once

#include <thread>
#include <queue>

template<int SIZE = std::thread::hardware_concurrency()>
class ThreadPool
{
public:
    ThreadPool()
    {
        
    }

private:
    const int numThreads = SIZE;
};
