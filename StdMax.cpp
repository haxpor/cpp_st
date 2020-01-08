/**
 * Demonstrate std::max can return 'const T&' which capture the maximum value but we cannot
 * capture it with 'T&' with intention to modify its value.
 */
#include <iostream>
#include <algorithm>

int main()
{
    int a = 10;
    int b = 20;
    int r = std::max(a, b);

    std::cout << "-- Scalar --\n";
    std::cout << "Max: " << r << '\n';
    std::cout << "a: " << a << '\n'
              << "b: " << b << "\n\n";

    const int& rr = std::max(a, b);
    std::cout << "-- Const Reference --\n";
    std::cout << "Max: " << rr << '\n';
    std::cout << "a: " << a << " address: " << std::addressof(a) << '\n'
              << "b: " << b << " address: " << std::addressof(b) << '\n'
              << "rr: " << rr << " address: " << std::addressof(rr) <<  std::endl;

    // the following line is not possible, you cannot capture with T&
    //int& rr = std::max(a, b);

    std::cout.flush();
    return 0;
}
