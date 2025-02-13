/**
 * Demonstrate how dangerous of VLA (Variable Length Array).
 *
 * Compile this program with
 *
 * g++ -std=c++11 -Wall -pedantic VLA.cpp
 *
 * Then check with your maximum stack size via `ulimit -s`, my system (Ubuntu 18.04) returns 8192,
 * note that the unit is in kbytes.
 *
 * Thus execute the program with `echo 2097153 | ./a.out`
 *
 * 2097153 comes from calculation of maximum size of stack in bytes 8192 * 1024 / 4 = 2097152.
 * wheres 8192 is stack size, 1024 for us to get unit in bytes, and 4 is size of std::int32_t.
 * Thus by increment the result by 1, we just exceed the stack size.
 *
 * Note: Anyway, from testing, it's not a clear cut that just a byte exceeding the stack maximum
 * limited size will produce segfault. From testing, only 2094010 will already crashed and produced
 * segfault. Those 3142 bytes.
 *
 * Further read https://www.reidatcheson.com/c/programming/2015/12/07/vlas.html
 *
 * Finally if you ensure that the input is small to medium value which could not be put into danger
 * the maximum stack size, then use it. Or otherwise, put comment into the code, or declare array on
 * heap. And do note, even const cast won't silence the warning as the expression is not constant.
 */
#include <iostream>
#include <cstddef>

int main()
{
    std::cout << "sizeof(std::int32_t) = " << sizeof(std::int32_t) << std::endl;

    // this is just to make sure we hold 4 bytes of integer type here
    // note: mostly even 64-bit system, compiler will set int as 4-bytes as in the case on my Ubuntu system
    std::int32_t n;
    std::cin >> n;

    std::cout << "n = " << n << std::endl;

    // even do const-cast won't silence the warning
    const std::int32_t N = static_cast<const std::int32_t>(n);
    // effectively use VLA, dangerous
    std::int32_t arr[N];
    std::cout << arr[N-1] << std::endl;

    // declare array on heap will solve the problem
    // note: we won't see compiler warning for this
    std::int32_t* arr2 = new std::int32_t[N];
    std::cout << arr2[N-1] << std::endl;
    delete[] arr2;
    return 0;
}
