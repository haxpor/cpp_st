/**
 * Demonstrate a way to allocate bytes on heap in C++ way.
 */

#include <iostream>

int main()
{
    int* nPtr = new int[10];
    for (int i=0; i<10; ++i)
    {
        nPtr[i] = i+1;
    }

    std::cout << "Address of nPtr: " << std::addressof(nPtr) << std::endl;
    std::cout << "Value of nPtr[5]: " << nPtr[5] << std::endl;
    std::cout << "Size: " << sizeof(int) * 10 << std::endl;
    return 0;
}
