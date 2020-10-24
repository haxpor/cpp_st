/**
  * Virtual functions called in constructor or destructor never directed to the actual subclass which
  * overrides it.
  */

#include <iostream>

class WidgetA
{
public:
    WidgetA()
    {
        std::cout << "WidgetA()" << std::endl;
        hello();    // never do any virtual function resolution, it call its own hello()
    }

    virtual ~WidgetA()
    {
        std::cout << "~WidgetA()" << std::endl;
        hello();    // never do any virtual function resolution, it call its own hello()
    }

    virtual void hello() const
    {
        std::cout << "WidgetA(): hello()" << std::endl;
        goodbye();
    }

    virtual void goodbye() const
    {
        std::cout << "WidgetA(): goodbye()" << std::endl;
    }
};

class WidgetB : public WidgetA
{
public:
    WidgetB()
    {
        std::cout << "WidgetB()" << std::endl;
        hello();    // never do any virtual function resolution, it call its own hello()
    }

    virtual ~WidgetB()
    {
        std::cout << "~WidgetB()" << std::endl;
        hello();    // never do any virtual function resolution, it call its own hello()
    }

    virtual void hello() const override
    {
        std::cout << "WidgetB(): hello()" << std::endl;
        goodbye();
    }

    virtual void goodbye() const override
    {
        std::cout << "WidgetB(): goodbye()" << std::endl;
    }
};

int main()
{
    WidgetA* ptr = new WidgetB();
    ptr->goodbye();
    delete ptr;
    return 0;
}
