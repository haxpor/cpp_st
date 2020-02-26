/**
 * Use `virtual` keyword or virtual base class to have just one copy of base class in inheritance chain.
 *
 * B inherits from A.
 * C inherits from A.
 * D inherits from B, and C.
 */
#include <iostream>

class A {
public:
    A() { std::cout << "A - ctor\n"; }
};

class B : virtual public A {
public:
    B() { std::cout << "B - ctor\n"; }
};

class C : virtual public A {
public:
    C() { std::cout << "C - ctor\n"; }
};

class D : public B, public C {      // multiple inheritance
public:
    D() { std::cout << "D - ctor\n"; }
};

int main() {
    D d;
    return 0;
}
