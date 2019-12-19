/**
 * Testbed on checking whether std::vector<scalar-type> is trivially copyable or not via
 * type traits.
 */
#include <type_traits>
#include <iostream>
#include <vector>

std::vector<unsigned int> vec;

int main()
{
    std::cout << std::boolalpha << std::is_trivially_copyable<std::vector<unsigned int>>::value  << std::endl;
    return 0;
}
