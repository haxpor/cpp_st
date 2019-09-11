/**
 * Demonstrate usage std::async.
 */

#include <iostream>
#include <future>

int main()
{
    auto sleep = []() -> int {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        return 1;
    };

    // this spawns and execute on a new thread
    auto f = std::async(std::launch::async, sleep);
    std::cout << "You can see this immediately" << std::endl;
    std::cout << f.get() << " This will be shown after 1 second" << std::endl;

    // this will NOT spawn a new thread, execute immediately
    // it can be called on any thread no need to be the same as a thread called std::async to create such std::future
    auto f2 = std::async(std::launch::deferred, sleep);
    std::cout << f2.get() << " This will be shown after 1 second" << std::endl;

    // create std::future like this will result in setting both policy flag
    // it's up to implementation defined, see result for yourself whether it goes for std::launch::async or std::launch::deferred
    auto f3 = std::async([]() -> int {
            std::this_thread::sleep_for(std::chrono::seconds(2));
            return 2;
            });
    std::cout << "Did you see this immediately? If so, then implementation follows std::launch::async" << std::endl;
    std::cout << f3.get() << "This will be shown after 2 seconds" << std::endl;

    auto f4 = std::async(std::launch::async, sleep);
    std::cout << "f4 is launched" << std::endl;
    auto f5 = std::async(std::launch::async, sleep);
    std::cout << "f5 is launched" << std::endl;

    // wait from both f4, and f5
    std::cout << f4.get() << " " << f5.get() << std::endl;

    return 0;
}
