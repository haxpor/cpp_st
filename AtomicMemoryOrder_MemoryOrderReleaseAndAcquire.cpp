/**
 * Test seeing the effect of setting memory order to release and acquire in different thread.
 * This has the same effect as sequential consistent when we didn't set anything; by default.
 * But it has minimal overhead (see https://stackoverflow.com/a/6319356/571227).
 *
 * Compile with the following flags
 *  -std=c++11 and -lpthread
 */
#include <iostream>
#include <thread>
#include <atomic>
#include <chrono>
#include <random>
#include <cassert>

#define SIZE 50

std::atomic<int> x[SIZE];
std::atomic<int> y[SIZE];

static void thread_work1(int i)
{
    x[i].store(1, std::memory_order_release);
    y[i].store(2, std::memory_order_release);
}

static void thread_work2(int i)
{
    int loaded_y = y[i].load(std::memory_order_acquire);
    int loaded_x = x[i].load(std::memory_order_acquire);

    // this case won't happen as CPU ensures sequential consistency
    assert(!(loaded_y == 2 && loaded_x == 0));

    std::cout << loaded_y << " "
              << loaded_x << std::endl;
}

int main()
{
    // we will random between [0, 25) ms to sleep between each iteration of loop
    std::uniform_int_distribution<int> distribution(0,25);
    std::mt19937 engine;    // overkill, but anyway

    for (int i=0; i<SIZE; ++i)
    {
        std::thread t1(thread_work1, i);
        std::thread t2(thread_work2, i);

        t1.join();
        t2.join();

        int sleepFor = distribution(engine);
        std::this_thread::sleep_for(std::chrono::milliseconds(sleepFor));
    }
    // at maximum, this program will finish in SIZE*25/1000 s
    return 0;
}
