/**
 * Use #define and #undef to help in overriding standard library function call.
 * "using namespace std" helps to avoid cannot find mymalloc() in std:: which is definitely not there.
 */
#include <iostream>
#include <cstdlib>

static char* mymalloc(size_t size)
{
    std::cout << "mymalloc called" << std::endl;
    return new char[size];
}

int main()
{
    // also the key to avoid cannot find myalloc of std:: which definitely not there
    using namespace std;

    #define malloc mymalloc
    // use our custom mymalloc()
    char* ptr = malloc(100);
    delete[] ptr;
    #undef malloc

    std::cout << "---" << std::endl;

    // use std::malloc()
    void* ptr2 = malloc(100);
    free(ptr2);

    return 0;
}
