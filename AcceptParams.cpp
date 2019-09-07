/**
 * Demonstrate how to accept program's argument.
 *
 * Execute the program by supplying at least 1 parameter like following
 *
 * ./a.out param1
 */

#include <iostream>

int main(int argc, char* argv[])
{
    // first parameter is program name
    if (argc >= 2)
    {
        for (int i=0; i<argc; ++i)
        {
            std::cout << "argv[" << i << "] = " << argv[i] << std::endl;
        }
    }
    else
    {
        std::cout << "Please supply at least 1 parameter to program\n";
        std::cout << "Usage: ./a.out param1" << std::endl;
    }
    return 0;
}
