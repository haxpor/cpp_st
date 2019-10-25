/**
 * Show that member methods don't contribute to the final size of class.
 */
#include <iostream>

struct Widget
{
    int a;
};

struct Widget2
{
    int a;

    void bar1();
    void bar2();
};

int main()
{
    std::cout << sizeof(Widget) << '\n';
    std::cout << sizeof(Widget2) << std::endl;
    return 0;
}
