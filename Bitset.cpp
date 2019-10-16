/**
 * Demonstrate usage of bitset.
 *
 * Bitset can be used with compile-time known size of N.
 * N should be size that allow it to be statically allocated within the stack size.
 * If N is not known at compile time, then use std::vector<bool>, or boost::dynamic_bitset.
 */
#include <iostream>
#include <bitset>

int main()
{
    std::bitset<100> achievements;

    std::cout << "Size: " << achievements.size() << std::endl;
    std::cout << "Count of bits set: " << achievements.count() << std::endl;

    // set bit
    achievements.set(56);
    std::cout << "56th was set\n";
    std::cout << "Count of bits set: " << achievements.count() << '\n';
    std::cout << "Is 56th bit set? (via operator[]): " << achievements[56] << '\n';
    std::cout << "Is 56th bit set? (via .test()): " << achievements.test(56) << '\n';

    std::cout << "Just check 55th\n";
    std::cout << "Is 55th bit set? (via operator[]): " << achievements[55] << '\n';
    std::cout << "Is 55th bit set? (via .test()): " << achievements.test(55) << '\n';

    std::cout << "Count of bits set: " << achievements.count() << std::endl;

    return 0;
}
