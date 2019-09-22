/**
 * Demonstrate how to forward declare class, and its definition later outside of the class which
 * wraps such declaration.
 *
 * Seen this for __future_base::_Async_state_impl which forward declared _Async_state_impl as class
 * inside its own struct definition. The definition of _Async_state_impl is outside of __future_base.
 *
 * To access class definition of B in order to create a new object on stack or heap, it requires to
 * specify as A::B as B is wrapped inside of class A scope. So this is a benefit of management.
 */
#include <iostream>

class A
{
public:
    class B;

    A() {}

    void Function() { std::cout << "A\n"; }
};

class A::B final
{
public:
    void Function() { std::cout << "B\n"; }
};

int main()
{
    A a;
    a.Function();

    A::B b;
    b.Function();

    std::cout.flush();
    return 0;
}
