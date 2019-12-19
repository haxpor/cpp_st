/**
 * Testbed on checking whether std::vector<scalar-type> is trivially copyable or not via
 * type traits.
 *
 * Read more about trivially copyable at Notes section in https://en.cppreference.com/w/cpp/types/is_trivially_copyable
 */
#include <type_traits>
#include <iostream>
#include <vector>

std::vector<unsigned int> vec;

int main()
{
    unsigned int arr[10];
    // std::vector is not trivially copyable
    std::cout << std::boolalpha << std::is_trivially_copyable<std::vector<unsigned int>>::value  << std::endl;

    // arr is a pointer, and pointer is trivially copyable
    std::cout << std::boolalpha << std::is_trivially_copyable<unsigned int[10]>::value << std::endl;
    return 0;
}
