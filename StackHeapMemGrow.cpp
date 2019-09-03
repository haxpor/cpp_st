/*
 * Demonstrate memory address growing in either direction for stack and heap.
 * After this should look into Castings.cpp.
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

    // note: low address is below, and high address is above
    // stack grows down (anyway it's not always guarantee to always be decreasing when printed)
    std::printf("%7s: %15p\n", "A", std::addressof(a));
    std::printf("%7s: %15p\n", "B", std::addressof(b));
    std::printf("%7s: %15p\n", "Derived", std::addressof(d));

    std::printf("\n");
    
    // heap
    A* aPtr = new A();
    B* bPtr = new B();
    Derived* dPtr = new Derived();

    // heap grows up (anyway it's not always guarantee to always be decreasing when printed)
    // thus you should see incresing address location from printed-out text on console on these lines
    std::printf("%7s: %15p\n", "A", std::addressof(aPtr));
    std::printf("%7s: %15p\n", "B", std::addressof(bPtr));
    std::printf("%7s: %15p\n", "Derived", std::addressof(dPtr));
    return 0;
}
