/*
 * Demonstrate usage of std::aligned_alloc.
 *
 * std::aligned_alloc is available since C++17.
 */
#include <iostream>
#include <cstdlib>

struct Widget
{
    int a;
    double b;
    double c;
};

int main()
{
    // allocate and construct all 10 elements via new operator
    // by default it will use alignof(Widget) as alignment bytes, thus we have no control
    // anyway, it's up to OS to find suitable starting address space whether it's aligned or not for us
    int* p1 = new int[10];
    std::cout << "default aligned-address (int): " << (void*)p1 << '\n';

    // same as above
    Widget* p2 = new Widget[10];
    std::cout << "default aligned-address (Widget): " << (void*)p2 << '\n';

    // allocate space for 10 elements of int with the same size as alignment
    int* p3 = static_cast<int*>(std::aligned_alloc(sizeof(int)*10, sizeof(int)*10));
    std::cout << "std::aligned_alloc aligned-address (int): " << (void*)p3 << '\n';

    // allocate space for 10 elements (notice we don't need to specify extra bytes for size to help
    // the function to aligned allocate memory as compared to DIY solution)
    Widget* p4 = static_cast<Widget*>(std::aligned_alloc(sizeof(Widget)*10, sizeof(Widget)*10));
    std::cout << "std::aligned_alloc aligned-address (Widget): " << (void*)p4 << '\n';

    return 0;
}
