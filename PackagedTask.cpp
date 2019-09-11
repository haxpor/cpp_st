/**
 * Demonstrate usage of std::packaged_task
 *
 * Under linux, you must link with -lpthread otherwise the following error will show
 *
 * terminate called after throwing an instance of 'std::system_error'
 * what():  Unknown error -1
 * Aborted (core dumped)
 *
 */

#include <iostream>
#include <future>

int main()
{
    auto sleep = []() -> int {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        return 1;
    };

    std::packaged_task<int()> task(sleep);
    auto f = task.get_future();

    std::cout << "Execute std::packaged_task\n";
    // for packaged_task, you have to manually invoke it
    task();
    std::cout << "You can see this after 1 seconds\n";
    std::cout << f.get() << std::endl;
    return 0;
}
