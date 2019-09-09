/**
 * Demonstrate usage of std::numeric_limits<T> to get maximum/minimum values of numeric type,
 * and how to implement it via template.
 */

#include <iostream>
#include <limits>
#include <iomanip>

int main()
{
    long minLong = std::numeric_limits<long>::min();
    long maxLong = std::numeric_limits<long>::max();

    std::cout << "Minimum value of long = " << std::setw(23) << std::right << minLong << "\n"
              << "Maximum value of long = " << std::setw(23) << std::right << maxLong << std::endl;

    return 0;
}
