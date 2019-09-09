/**
 * Demonstrate how to implement type traits.
 * Kindly working on top of std::numeric_limits.
 */

#include <iostream>
#include <type_traits>
#include <iomanip>

template <typename T>
struct DummyType
{
    typedef T type;
    static T min() noexcept { return T(); }
    static T max() noexcept { return T(); }
};

template <>
struct DummyType<long>
{
    typedef long type;
    static long min() noexcept { return 10; }       // just for testing purpose, in reality should be minimum value of certain type
    static long max() noexcept { return 100; }      // just for testing purpose, in reality should be maximum value of certain type
};

int main()
{
    long minDummyLong = DummyType<long>::min();
    long maxDummyLong = DummyType<long>::max();

    std::cout << "Minimum value of DummyType<long> = " << std::setw(10) << std::right << minDummyLong << "\n"
              << "Maximum value of DummyType<long> = " << std::setw(10) << std::right << maxDummyLong << std::endl;

    // there's no specialized template for DummyType<int> then T() initialized to be 0
    int minDummyInt = DummyType<int>::min();
    std::cout << minDummyInt << std::endl;

    DummyType<long>::type myValue = 1090;
    std::cout << "myValue = " << myValue << std::endl;
    // std::is_same operates at compile-time
    if (std::is_same<DummyType<long>::type, long>::value)
    {
        std::cout << "DummyType<long>::type has type of long" << std::endl;
    }
    else
    {
        std::cout << "DummyType<long>::type doesn't have type of long" << std::endl;
    }

    if (std::is_same<decltype(myValue), DummyType<long>::type>::value)
    {
        std::cout << "myValue has the same type of DummyType<long>::type" << std::endl;
    }
    else
    {
        std::cout << "myValue has different type of DummyType<long>::type" << std::endl;
    }

    return 0;
}
