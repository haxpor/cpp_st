/**
 * Demonstrate order of destruction for various variable type and scope it's declared.
 */

#include <iostream>

using namespace std;

// definitions
class A {
public:
    ~A() { cout << "Destructor A" << endl; };
};


class B {
public:
    ~B() { cout << "Destructor B" << endl; };
};

class C {
public:
    ~C() { cout << "Destructor C" << endl; };
};

class D {
public:
    ~D() { cout << "Destructor D" << endl; };
};

class E {
public:
    ~E() { cout << "Destructor E" << endl; };
};

class F {
public:
    ~F() { cout << "Destructor F" << endl; };
};

// declarations
// all of these will be destroyed in reverse order, static variable is no matter, all the same
C c;
static E e;
F f;

int main()
{
    A* aPtr = new A();
    B b;
    static D d;     // this will be the last to be destroyed after all of these variables in this scope
                    // static variable is matter
    delete aPtr;
    
    return 0;
}
