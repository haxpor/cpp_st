/**
 * Demonstrate the difference between std::vector::reserve and std::vector::resize().
 * reserve will not affect vector's size, but resize will affect.
 */
#include <vector>
#include <iostream>

int main()
{
    std::vector<int> v;
    v.reserve(5);           // this won't affect size()

    std::cout << v.size() << ", " << v.capacity() << std::endl;

    v.insert(v.begin(), {1,2,3,4,5});

    std::cout << v.size() << ", " << v.capacity() << std::endl;

    v.resize(10);           // this will affect size()

    std::cout << v.size() << ", " << v.capacity() << std::endl;

    for (const int& i: v)
        std::cout << i << " ";
    return 0;
}
