/**
 * Demonstrate the use of std::isnormal to check whether input floating-point number is normal(ized)
 * or not i.e. not subnormal, NAN, INFINITY, zero.
 */
#include <iostream>
#include <cmath>
#include <limits>
#include <cfloat>

int main()
{
    float minPositiveFloat = std::numeric_limits<float>::min();
    float minFloatExp = std::numeric_limits<float>::min_exponent;
    float bitsFloatSignificant = std::numeric_limits<float>::digits;

    std::cout << std::boolalpha
              << "isnormal(std::numeric_limits<float>::min = " << std::boolalpha << std::isnormal(minPositiveFloat) << '\n'
              << "isnormal(std::pow(2,std::numeric_limits<float>::min_exponent) * std::pow(2,std::numeric_limits<float>::digits)) = " << std::boolalpha << std::isnormal(std::pow(2,std::numeric_limits<float>::min_exponent) * std::pow(2,std::numeric_limits<float>::digits)) << '\n'
              << "isnormal(0.000111010106782112355/2.0) = " << std::isnormal(0.000111010106782112355/2.0) << '\n'
              << "isnormal(DBL_MIN/2.0) = " << std::isnormal(DBL_MIN/2.0) << '\n'
              << "isnormal(NAN) = " << std::isnormal(NAN) << '\n'
              << "isnormal(INFINITY) = " << std::isnormal(INFINITY) << '\n'
              << "isnormal(0.0) = " << std::isnormal(0.0) << '\n';
    return 0;
}
