/**
 * Demonstrate the usage of atomic variables and its memory model constraint which we can set.
 *
 * See https://gcc.gnu.org/wiki/Atomic/GCCMM/AtomicSync for more detail for each type of memory model
 * we can set.
 */

#include <iostream>
#include <thread>
#include <atomic>
#include <cassert>

// variables that are shared among all threads created by this process
// note: constructor, and copy assignment operator is deleted
std::atomic<int> x;
std::atomic<int> y;
int local = 0;

static void t1Worker()
{
    local = 1;
    x.store(2);

    std::cout << "done - thread 1" << std::endl;
}

static void t2Worker()
{
    if (x.load() == 2)
    {
        std::cout << "modify" << std::endl;
        assert(local == 1);
    }
}

int main()
{
    // start thread 1 first to make sure 'local' variable is set
    // thus thread 2 will enter into if statement
    // anyway you can defer 't1.join()' later after both threads started, but there is no guarantee
    // which thread will start first
    std::thread t1 (t1Worker);
    t1.join();

    std::thread t2 (t2Worker);
    t2.join();

    std::cout << "done" << std::endl;
    return 0;
}
