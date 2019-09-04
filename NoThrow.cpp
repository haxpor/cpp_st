/*
 * Exactly use code from https://en.cppreference.com/w/cpp/memory/new/nothrow.
 *
 * Now that all un-free memory which is dynamically created during the runtime will be all freed
 * after the program finishes. Thus we don't manage memory clean up during runtime here.
 */

#include <iostream>
#include <new>

int main()
{
    try
    {
        while (true)
        {
            new int[100000000ul];
        }
    }
    catch (const std::bad_alloc& e)
    {
        std::cout << e.what() << std::endl;
    }

    while (true)
    {
        int* p = new(std::nothrow) int[100000000ul];
        if (p == nullptr)
        {
            std::cout << "Allocation returned nullptr" << std::endl;
            break;
        }
    }
    
    return 0;
}
