/**
 * Demonstrate usage of pure virtual function with or without keyword of override for derived class
 * that implements such function.
 *
 * It has the same result. We can put 'override' keyword there, or not use at all. It's fine.
 */
#include <iostream>

class Widget
{
public:
    virtual void bar() = 0;
    virtual void foo() = 0;
};

class DerivedWidget: public Widget
{
public:
    void bar()
    {
        std::cout << "bar" << std::endl;
    }

    void foo() override
    {
        std::cout << "foo" << std::endl;
    }
};

int main()
{
    DerivedWidget dw;
    dw.bar();
    dw.foo();
    return 0;
}
