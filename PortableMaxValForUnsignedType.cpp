/**
 * Demonstrate the portable way to define maximum value for unsigned type.
 * Read more detail in man page of std::basic_string::npos in which case it has value of -1 but
 * notice its data type is size_t which is unsigned integer type.
 *
 * That is the portable way to define maximum value for unsigned type due to signed-to-unsigned
 * implicit conversion.
 */

#include <iostream>
#include <limits>

int main()
{
    std::cout << "sizeof(unsigned int) = " << sizeof(unsigned int) << std::endl;
    std::cout << "maximum value of unsigned int (from std::numberic_limits<unsigned int>::max()): " << std::numeric_limits<unsigned int>::max() << std::endl;
    unsigned int maxValue = -1;
    std::cout << "maximum value of unsigned int (from -1 technique): " << maxValue << std::endl;
    std::cout << "equal?: " << std::boolalpha << (maxValue == std::numeric_limits<unsigned int>::max()) << std::endl;
    return 0;
}
