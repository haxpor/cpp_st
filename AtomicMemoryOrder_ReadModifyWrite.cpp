/**
 * Demonstrate how to use memory_order_acq_rel (or read-modify-write operation).
 *
 * Imagine a case when need to load, then modify value then store. Use this memory order.
 *
 * The difference between memory_order_acq_rel and by default memory_order_seq_cst is that the former
 * is relative to the atomic variable, but the latter is globally. Both for read/write. Check
 * AtomicMemoryOrder_MemoryOrderSeqCst.cpp for the later usage.
 *
 */
#include <iostream>
#include <atomic>
#include <thread>
#include <chrono>

std::atomic<int> data;
std::atomic<bool> readyFlag;

// thread worker to set data value
// then also set the readyFlag
void threadWorkerProducer()
{
    // delay a short time to simulate thread consumer to wait for a while
    std::this_thread::sleep_for(std::chrono::milliseconds(100));

    readyFlag.store(true, std::memory_order_release);
    data.store(50, std::memory_order_release);

    // delay a short time for a second phase
    std::this_thread::sleep_for(std::chrono::milliseconds(500));
    data.store(100, std::memory_order_release);

    std::cout << "Producer thread finished\n";
}

void threadWorkerConsumer()
{
    while (!readyFlag.load(std::memory_order_acquire))
    {
        int expectedDummy = 100;

        // compare_exchange_strong compare value of atomic variable to expectedDummy.
        // If both are equal, then it will assign 200 as value to such atomic variable via memory
        // order std::memory_order_acq_rel.
        //
        // But if it isn't equal, then it will assign current value from atomic variable to expectedDummy
        // via memory order of std::memory_order_release.
        //
        // I think this mechasim which requires real variable to be the first parameter as we will
        // most likely need to peek into current value of such atomic variable, and make any use of it (if any).
        // So we have responsibility to set value of expected variable back to what we need to be checked
        // against at the first place provided that we use while loop to keep checking.
        while (!data.compare_exchange_strong(expectedDummy, 200,  std::memory_order_acq_rel, std::memory_order_release))
        {
            // reset expected value back to normal
            // as if the case is false then its value is updated to be whatever value 'data'
            // currently has
            expectedDummy = 100;
        }
        std::cout << "Modified 'data' value to 200\n";
    }

    std::cout << "Consumer thread finished\n";
}

int main()
{
    // set the intial state of ready flag
    // use relaxed memory model as we're sure there's no contension,
    readyFlag.store(false, std::memory_order_relaxed);

    std::thread t1(threadWorkerProducer);
    std::thread t2(threadWorkerConsumer);

    t1.join();
    t2.join();

    std::cout << "[Main thread] data: " << data.load(std::memory_order_acquire) << std::endl;

    return 0;
}
