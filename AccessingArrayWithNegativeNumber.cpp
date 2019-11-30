/**
 * Test using negative number in indexing of array (or can be pointer, the same).
 */

#include <iostream>

int main()
{
    int before = 6;
    int array[5] = {1,2,3,4,5};
    // this is equal to *(array-1) thus will print what every int value there in the memory before it
    // thus it's `before` which is 6
    std::cout << array[-1] << std::endl;
    return 0;
}
