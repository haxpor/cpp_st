/**
 * Test atomic with relaxed memory order.
 *
 * Compile with the following flags
 *  -std=c++11 and -lpthread
 */
#include <iostream>
#include <thread>
#include <atomic>
#include <chrono>
#include <random>

#define SIZE 50

std::atomic<int> x[SIZE];
std::atomic<int> y[SIZE];

static void thread_work1(int i)
{
    x[i].store(1, std::memory_order_relaxed);
    y[i].store(2, std::memory_order_relaxed);
}

static void thread_work2(int i)
{
    int loaded_y = y[i].load(std::memory_order_relaxed);
    int loaded_x = x[i].load(std::memory_order_relaxed);

    std::cout << loaded_y << " "
              << loaded_x;
    if (loaded_y == 2 && loaded_x == 0)
        std::cout << " [out-of-order]";
    std::cout << std::endl;
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
