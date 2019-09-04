/**
 * Demonstrate implementation of overloading assignment operator function.
 *
 * Compile with -fno-elide-constructors.
 */

#include <iostream>

class Widget
{
public:
    Widget(): a(0)
    {
        std::cout << "ctor(1)" << std::endl;
    }

    Widget(const int a): a(a)
    {
        std::cout << "ctor(2)" << std::endl;
    }

    Widget(const Widget& obj): a(obj.a)
    {
        std::cout << "ctor(3)" << std::endl;
    }

    Widget(Widget&& obj): a(obj.a)
    {
        std::cout << "ctor(4)" << std::endl;
    }

    // it will select whether to do copy object, or move depending on what's on the right
    // side of assignment operator (rhs). Thus if we implement move copy constructor, then
    // it will select to use it for more performance; reduce 1 (usually expensive) copying step.
    Widget& operator= (Widget obj)
    {
        std::cout << "operator= called(1)" << std::endl;

        a = obj.a;
        return *this;
    }

    // NO NEED to define the following overloaded function anymore
    // as it will make it ambiguous to compiler.
    //Widget& operator= (const Widget& obj)
    //{
    //    std::cout << "operator= called(2)" << std::endl;

    //    a = obj.a;
    //    return *this;
    //}

    const int GetA() const
    {
        return a;
    }
    
private:
    int a;
};

int main()
{
    Widget a(1);
    Widget b(2);
    // by copying value sending b into assignment operator function
    a = b;
    std::cout << "a.a = " << a.GetA() << std::endl;

    // by move semantics sending Widget(5) into assignment operator function
    a = Widget(5);
    std::cout << "a.a = " << a.GetA() << std::endl;
    return 0;
}
