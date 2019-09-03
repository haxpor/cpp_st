/**
 * Demonstrate simple calling order from derived class to its parent class.
 */

#include <iostream>

class A
{
public:
    void FuncA()
    {
        std::cout << "FuncA called\n";
    }

    virtual void FuncB()
    {
        std::cout << "FuncB called\n";
    }
};

class B : public A
{
public:
    void FuncA()
    {
        A::FuncA();
        std::cout << "FuncAB called\n";
    }

    virtual void FuncB()
    {
        std::cout << "FuncBB called\n";
    }
};

int main()
{
    B b;
    A *pa = &b;

    // FuncA is not virtual, thus it will call A's FuncA() only
    pa->FuncA();
    // Func B is virtual, thus it will call B's FuncB()
    pa->FuncB();
    
    // flush the output stream
    std::cout.flush();
    return 0;
}
