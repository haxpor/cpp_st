// check assembly output compiling with MSVC at https://gist.github.com/haxpor/19b0236a07a525999721e3ec3432af1b
#include <initializer_list>
#include <iostream>

struct Widget
{
    Widget(int n) { std::cout << "normal ctor called" << std::endl; }
    Widget(std::initializer_list<long double> il) { std::cout << "initializer_list ctor called" << std::endl; }

    operator float() const
    {
        std::cout << "cast operator float() called" << std::endl;
        return 2.0f;
    }

    // uncomment to have direct cast operator available to be called by w2 (below)
    // otherwise it will use float casting operator instead
    /*
    operator long double() const
    {
        std::cout << "cast operator long double() called" << std::endl;
        return 2.0;
    }
    */
};

int main()
{
    Widget w1(1);
    Widget w3{w1};
    Widget w4{std::move(w1)};
    return 0;
}
