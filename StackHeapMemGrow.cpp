/*
 * Demonstrate memory address growing in either direction for stack and heap.
 * After this should look into Castings.cpp.
 *
 * When compiled, you will probably encounter the following compile error
 *
 * StackHeapMemGrow.cpp:18:7: warning: direct base ‘A’ inaccessible in ‘Derived’ due to ambiguity
 class Derived : public A, public B
 * 
 * This is due to multiple inheritance which should be avoided, but used in this case for studying
 * purpose.
 */

#include <iostream>

class A
{
    int a;
};

class B : public A
{
    int b;
};

class Derived : public A, public B
{
    int d;
};

int main()
{
    // stack
    A a;
    B b;
    Derived d;
    int ai;
    double bi;

    // note: low address is below, and high address is above
    // stack grows down (anyway it's not always guarantee to always be decreasing when printed)
    std::printf("%7s: %15p\n", "A", std::addressof(a));
    std::printf("%7s: %15p\n", "B", std::addressof(b));
    std::printf("%7s: %15p\n", "Derived", std::addressof(d));
    std::printf("%7s: %15p\n", "ai", std::addressof(ai));
    std::printf("%7s: %15p\n", "bi", std::addressof(bi));

    std::printf("\n");
    
    // heap
    A* aPtr = new A();
    B* bPtr = new B();
    Derived* dPtr = new Derived();

    // heap grows up (anyway it's not always guarantee to always be increasing when printed)
    // thus you should see incresing address location from printed-out text on console on these lines
    std::printf("%7s: %15p\n", "A", std::addressof(aPtr));
    std::printf("%7s: %15p\n", "B", std::addressof(bPtr));
    std::printf("%7s: %15p\n", "Derived", std::addressof(dPtr));
    return 0;
}
