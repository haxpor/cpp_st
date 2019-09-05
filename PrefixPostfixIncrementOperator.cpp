/**
 * Demonstrate how to overload prefix and postfix increment operator function.
 */

#include <iostream>

class Widget
{
public:
    int a;

    // prefix increment operator
    Widget& operator++()
    {
        ++a;
        return *this;
    }

    // postfix increment operator
    Widget operator++(int)
    {
        Widget tmp = *this;
        ++a;
        return tmp;
    }
};

int main()
{
    Widget w1; w1.a = 1;
    Widget w2; w2.a = 2;

    Widget t;
    t = w1++;
    std::cout << t.a << " " << w1.a << std::endl;
    
    t = ++w2;
    std::cout << t.a << " " << w2.a << std::endl;

    return 0;
}
