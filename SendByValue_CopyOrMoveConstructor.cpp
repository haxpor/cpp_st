/**
 * Demonstrate how to construct
 *  - copy constructor
 *  - move copy constructor
 *
 *  and centralize (stil have to do at copy constructor with input of another object).
 *  Swap function which is the central code base for object's member variables-copying
 *  through a single implementation of copy assignment operator function, this will let compiler picks
 *  move constructor when input is rvalue and use it without us writing any line code for
 *  move assignment operator.
 *
 *  Compile note:
 *  Use 'g++ -std=c++11 -fno-elide-constructors <source-file>' to not let compiler optimize RVO
 *  for us which will result 
 *
 *  Note several links referenced throughout the source code.
 */

#include <iostream>
#include <utility>

class Widget
{
private:
    int a;

public:
    Widget() : a(0) 
    {
        std::cout << "[Widget] Called ctor(1)" << std::endl;
    }

    Widget(const int a) : a(a)
    {
        std::cout << "[Widget] Called ctor(2)" << std::endl;
    }

    Widget(const Widget& x) : a(x.a)
    {
        std::cout << "[Widget] Called ctor(3)" << std::endl;
    }

    // this calls constructor delegate
    // see https://www.geeksforgeeks.org/constructor-delegation-c/, and https://stackoverflow.com/a/3279550/571227
    Widget(Widget&& x) : a(x.a)
    {
        std::cout << "[Widget] Called ctor(4)" << std::endl;
    }

    const int GetA() const
    {
        return a;
    }

    // centralize swap function to one location
    // declaring function like this to get copy constructor to work for free, and allow us to
    // do just that; centralize swap function thus reduce code, reduce error prone.
    // At the same time, also provide move constructor to let compiler pick it up as it is rvalue.
    // see https://stackoverflow.com/a/3279550/571227
    Widget& operator= (Widget rhs)
    {
        std::cout << "[Widget] Called operator= (1)" << std::endl;

        // we get copy constructor for free
        // next is to swap (copy-swap-idiom)
        Swap(*this, rhs);
        // by convention, return *this
        return *this;
    }

    // extra tip:
    // interesting note about noexcept is that it is usually checked at STL code level, or 
    // one great example is std::vector which will use user's move method when it's marked with
    // noexcept only.
    //
    // Swap function here is to swap each member variables, not the object itself, otherwise
    // endless move assignment operator function calls will happen.
    //
    // Defined as friend function because this functionality should not be as part of the class.
    //
    // Read more: https://stackoverflow.com/a/10788136/571227
    friend void Swap(Widget& first, Widget& second) noexcept
    {
        std::cout << "[Widget] Called Swap" << std::endl;

        // ADL, to super ensure that we call std::swap and not others
        using std::swap;

        // do this for all its member variables here
        swap(first.a, second.a);
    }
};

int main()
{
    Widget a(11);
    std::cout << "a.a = " << a.GetA() << std::endl;

    // lvalue
    Widget b = a;
    std::cout << "b.a = " << b.GetA() << std::endl;
    // rvalue
    a = Widget(5);
    std::cout << "c.a = " << a.GetA() << std::endl;

    return 0;
}
