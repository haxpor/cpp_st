/**
 * Demonstrate usage of std::numeric_limits<T> to get maximum/minimum values of numeric type,
 * and how to implement it via template.
 */

#include <iostream>
#include <limits>
#include <iomanip>

typedef long long mylong;

template <typename T>
static void PrintMinMaxValue()
{
    T minLong = std::numeric_limits<T>::min();
    T maxLong = std::numeric_limits<T>::max();

    // typeid() evaluate in run-time, thus use RTTI
    std::cout << "Minimum value of " << typeid(T).name() << " = " << std::setw(23) << std::right << minLong << "\n"
              << "Maximum value of " << typeid(T).name() << " = " << std::setw(23) << std::right << maxLong << std::endl;
}

int main()
{
    PrintMinMaxValue<int>();
    PrintMinMaxValue<long>();
    PrintMinMaxValue<float>();
    PrintMinMaxValue<double>();
    PrintMinMaxValue<mylong>();

    return 0;
}
