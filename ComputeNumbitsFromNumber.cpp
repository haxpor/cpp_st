/**
 * Demonstrate specialized template to compute number of bits to represent input number.
 * We will only implement specialized template function only for integer type, not floating point type
 * just for pure purpose. It doesn't mean floating point number cannot be represented in binary form though.
 *
 * Version 1
 */

#include <iostream>

// base class template
template <typename T>
class Widget
{
public:
    // a function template inside a class template
    // note:: this is a recommended way to do it, try to avoid doing function template alone if you
    // intended to specialize it later (which is not recommended)
    // Read more at http://www.gotw.ca/publications/mill17.htm further
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
};

// specialized class template that signifies un-implemented by returning 0 as always
template <>
class Widget<float>
{
public:
    static const float ComputeNumBits(float n)
    {
        // not implemented, just always return 0
        return 0;
    }
};

template <>
class Widget<double>
{
public:
    static const double ComputeNumBits(double n)
    {
        // not implemented, just always return 0
        return 0;
    }
};

int main()
{
    std::cout << "Number of bits to represent:\n";
    std::cout << " 1024: " << Widget<int>::ComputeNumBits(1024) << std::endl;
    std::cout << " 1024 (long): " << Widget<long>::ComputeNumBits(1024) << std::endl;
    std::cout << " 1024.0f: " << Widget<float>::ComputeNumBits(1024.f) << std::endl;
    std::cout << " 1024.0: " << Widget<double>::ComputeNumBits(2014.0) << std::endl;
    return 0;
}
