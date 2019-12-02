/**
 * Demonstrate the use of `inline` keyword for constructor and destructor.
 *
 * Additional
 *  - Boost library mentioned in this question of SO reported to be using `inline` for their
 *    constructor https://stackoverflow.com/q/44247614/571227
 */

#include <iostream>

class Widget
{
public:
    inline Widget(): a(0)
    {
        std::cout << "ctor - 1\n";
    }

    inline Widget(int a): a(a)
    {
        std::cout << "ctor - 2\n";
    }

    inline virtual ~Widget()
    {
        std::cout << "dtor(" << a << ')' << '\n';
    }

    int getA() const { return a; }

private:
    int a;
};

int main()
{
    Widget a;
    std::cout << a.getA() << '\n';

    Widget b(2);
    std::cout << b.getA() << '\n';
    return 0;
}
