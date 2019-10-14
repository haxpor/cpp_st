/**
 * Demonstrate usage of atomic by setting memory order to see its effect.
 *
 * Compile with the following flags
 *  -std=c++11 and -lpthread
 *
 * Then try to run it multiple times, we will see two results.
 *
 * Thread 1 or 2 can be executed before one another.
 * Thus it can print out
 *  0 1 or
 *  2 1
 */
#include <iostream>
#include <thread>
#include <atomic>

std::atomic<int> x;
std::atomic<int> y;

static void thread_work1()
{
    // c++11 's memory model ensure "sequential consistency"
    // x.store(1) will happen before y.store(2)
    // continue seeing the comment in thread_work2()
    x.store(1);
    y.store(2);
}

static void thread_work2()
{
    // ...continued
    // thus this means it cannot print 2 0
    // as x will be definitely loaded with 1 before y is loaded
    std::cout << y.load() << " ";
    std::cout << x.load() << std::endl;
}

int main()
{
    std::thread t1(thread_work1);
    std::thread t2(thread_work2);

    t1.join();
    t2.join();
    return 0;
}
