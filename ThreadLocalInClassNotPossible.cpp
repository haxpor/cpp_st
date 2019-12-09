/**
 * Based on top of ThreadLocal.cpp
 *
 * Using thread_local inside a class is not possible as it will show 'TLS wrapper function for ThreadLocalWrapper::localWidget'
 * in link time. If you know how to fix this, you can send pull request, thanks!
 *
 * [Extra]
 *  - this is also shown how to send in member function for thread to invoke
 *
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

class ThreadLocalWrapper
{
public:
    ThreadLocalWrapper()
    {
        // this is also shown how to send in member function for thread to invoke
        std::thread t1(&ThreadLocalWrapper::thread1, this);
        std::thread t2(&ThreadLocalWrapper::thread2, this);
        std::thread t3(&ThreadLocalWrapper::thread3, this);
        std::thread t4(&ThreadLocalWrapper::thread4, this);

        t1.join();
        t2.join();
        t3.join();
        t4.join();
    }

private:
    // attempt this line and it's shown the error like commented in the top
    //static thread_local Widget localWidget;

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
};

int main()
{
    ThreadLocalWrapper();
    std::cout.flush();

    return 0;
}
