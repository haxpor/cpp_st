/**
 * Demonstrate the adapted code example from https://en.cppreference.com/w/cpp/thread/condition_variable
 *
 * It's involved using std::unique_lock, std::lock_guard; which in turns involves using std::mutex.
 */

#include <iostream>
#include <string>
#include <mutex>
#include <thread>
#include <condition_variable>

// whole program uses the same mutex
static std::mutex mx;

// condition_variable is here to help waiting to acquire the lock as per set condition
static std::condition_variable cv;

// shared data as multiple threads will access and modify
static std::string data;
static bool ready = false;
static bool processed = false;

static void worker_thread()
{
    std::unique_lock<std::mutex> lock(mx);
    // wait until it becomes ready
    // the reason why conditinal_variable needs mutex lock because to prevent other thread from
    // intervening it while it's waiting as other threads might intervene and send notify even before
    // it can wait and do anything
    // see: https://stackoverflow.com/a/46088977/571227
    cv.wait(lock, []() { return ready; });

    // after the wait, we now own the lock
    std::cout << "Worker thread is processing data" << std::endl;
    // extra note: this line can be seen as also optimized version
    // as if operator+ is called with input argument of rvalue reference, then internally
    // it will return via std::move and can take advantage of RVO by compiler
    // see more discussion at https://stackoverflow.com/questions/611263/efficient-string-concatenation-in-c#comment76478884_611279
    data += " after processing";

    // send data back to main()
    processed = true;
    std::cout << "Worker thread signals data processing completed" << std::endl;

    // unlock first before we will notify one of waiting threads
    lock.unlock();
    // unblock one of the waiting thread
    cv.notify_one();
}

int main()
{
    std::thread worker(worker_thread);

    data = "Example data";
    // send data to the worker thread
    {
        std::lock_guard<std::mutex> lock(mx);
        ready = true;
        std::cout << "main() signals data ready for processing" << std::endl;
    }
    cv.notify_one();

    // wait for the worker
    {
        std::unique_lock<std::mutex> lock(mx);
        cv.wait(lock, []() { return processed; });
    }
    std::cout << "Back in main(), data = " << data << std::endl;

    worker.join();
    return 0;
}
