/**
 * Demonstrate the effect of std::future's destructor
 */

#include <iostream>
#include <future>

int main()
{
    {
        std::future<void> f = std::async(std::launch::async, []() {
                std::this_thread::sleep_for(std::chrono::seconds(1));
                });
        // this will block until spawned thread completes
        // as it is the last thread reference to such std::future, it need
        // to deallocate shared_state created at the creation time
    }

    // we will see this after 1 second
    std::cout << "Continued" << std::endl;
    return 0;
}
