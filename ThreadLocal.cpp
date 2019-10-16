/**
 * Demonstrate thread_local usage.
 *
 * Extra: use atomic_flag to synchronize printing out onto console.
 */
#include <iostream>
#include <thread>
#include <atomic>

// use to synchronize printing onto console
static std::atomic_flag lock = ATOMIC_FLAG_INIT;

struct Widget
{
    int i;

    Widget() = default;
    ~Widget()
    {
        while (lock.test_and_set(std::memory_order_acquire))
            ;
        std::cout << i << '\n';
        lock.clear();
    }
};

// local variable for each thread
// notice when we set Widget::i for each thread, it has different value as shown in its destructor.
thread_local Widget localWidget;

void thread1()
{
    localWidget.i = 1;
}

void thread2()
{
    localWidget.i = 2;
}

void thread3()
{
    localWidget.i = 3;
}

void thread4()
{
    localWidget.i = 4;
}

int main()
{
    std::thread t1(thread1);
    std::thread t2(thread2);
    std::thread t3(thread3);
    std::thread t4(thread4);

    t1.join();
    t2.join();
    t3.join();
    t4.join();

    std::cout.flush();

    return 0;
}
