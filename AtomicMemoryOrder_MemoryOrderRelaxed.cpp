/**
 * Test seeing the effect of setting memory order to relaxed (memory_order_relaxed)
 *
 * Compile with the following flags
 *  -std=c++11 and -lpthread
 *
 * Notice if output line is printed with "[out-of-order]",
 * this means sequential consistency is not ensured as normally did.
 * It doesn't mean bad case, but it's the thing we are willing to accept it to happen as we use
 * memory order relaxed (std::memory_order_relaxed).
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
    // with relaxed memory order like this
    // and in thread_work2() code like we have
    // this means we are ok if it prints 2 0 (no ensuring of x.store() to happen before y.store()
    x[i].store(1, std::memory_order_relaxed);
    y[i].store(2, std::memory_order_relaxed);
}

static void thread_work2(int i)
{
    int load_y = y[i].load(std::memory_order_relaxed);
    int load_x = x[i].load(std::memory_order_relaxed);

    std::cout << load_y << " " << load_x;
    if (load_x == 0)
        std::cout << " [out-of-order]" << std::endl;
    else
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
