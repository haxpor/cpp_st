/**
 * Demonstrate specialized template to compute number of bits to represent input number.
 * We will only implement specialized template function only for integer type, not floating point type
 * just for pure purpose. It doesn't mean floating point number cannot be represented in binary form though.
 *
 * Version 2
 */

#include <iostream>

// Not recommend to overload function template, thus we do normal overload function with same signature
// Read more at http://www.gotw.ca/publications/mill17.htm further
template <typename T>
static const T ComputeNumBits(T n)
{
    T numbits = 0;
    
    while (n > 0)
    {
        n >>= 1;
        ++numbits;
    }

    return numbits-1;
}

// Just return 0 to notifies that it's un-implemented
// We did normal overloaded function instead, not overloaded function template
static const float ComputeNumBits(float n)
{
    return 0;
}

// We did normal overloaded function instead, not overloaded function template
static const double ComputeNumBits(double n)
{
    return 0;
}

int main()
{
    std::cout << "Number of bits to represent:\n";
    std::cout << " 1024: " << ComputeNumBits(1024) << std::endl;
    std::cout << " 1024 (long): " << ComputeNumBits(1024) << std::endl;
    std::cout << " 1024.0f: " << ComputeNumBits(1024.f) << std::endl;
    std::cout << " 1024.0: " << ComputeNumBits(2014.0) << std::endl;
    return 0;
}
