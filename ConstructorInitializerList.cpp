/**
 * Validate which constructor or assignment operator initializer list will call.
 * It turns out it calls the first version of copy constructor.
 *
 * This is called "direct initialization" of constructor as matched 6.) at https://en.cppreference.com/w/cpp/language/direct_initialization
 */
#include <iostream>
#include <algorithm>

struct Widget
{
    Widget(int i_)
        : i(i_)
    {
        std::cout << "ctor 1" << std::endl;
    }

    Widget(const Widget& w)
        : i(w.i)
    {
        std::cout << "ctor 2" << std::endl;
    }

    Widget& operator=(const Widget& other)
    {
        std::cout << "assignment operator" << std::endl;
        i = other.i;
        return *this;
    }
    
    Widget& operator=(Widget&& other)
    {
        std::cout << "move assignment operator" << std::endl;
        i = std::move(other).i;
        return *this;
    }

    int i;
};

struct Foo
{
    Foo()
        : w(Widget(2))      // this line has equal effect as of the next line
        //: w(2)
    {
    }

    Widget w;
};

int main()
{
    Foo f;
    std::cout << f.w.i << std::endl;
    return 0;
}
