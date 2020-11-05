/**
 * Demonstrate that abstract class can inherit another abstract class.
 */
#include <iostream>

struct AbstractA {
    virtual void dummyFuncA() = 0;
};

struct AbstractB : public AbstractA {
    virtual void dummyFuncB() = 0;
};

struct Concrete : public AbstractB {
    void dummyFuncA() override {
        std::cout << "dummyFuncA" << std::endl;       
    }

    void dummyFuncB() override {
        std::cout << "dummyFuncB" << std::endl;       
    }
};

int main()
{
    Concrete c;
    c.dummyFuncA();
    c.dummyFuncB();
    return 0;
}
