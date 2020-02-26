/**
 * Multiple inheritance with 2 copies of base class appearing in constructor calls.
 * See MultipleInheritanceVirtual.cpp for solution to have just 1 copy.
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

class B : public A {
public:
    B() { std::cout << "B - ctor\n"; }
};

class C : public A {
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
