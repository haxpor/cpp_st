/**
 * Demonstrate of validate the order of call in constructor/destructor methods for base, derived class and its
 * member variable.
 *
 * The order in which things will be initialized for a single class definition is as follows
 *  - MyClass
 *      Member 1
 *      Member 2
 *      Member 3
 *  - Constructor
 *      Member 1
 *      Member 2
 *      Member 3
 *      MyClass
 *  - Destructor
 *      MyClass
 *      Member 1
 *      Member 2
 *      Member 3
 *
 *  The correct result in this case should be
 *  13156242
 */
#include <iostream>

class A
{
public:
    A() { std::cout << "1"; }
    ~A() { std::cout << "2"; }
};

class B
{
public:
    B() { std::cout << "3"; }
    ~B() { std::cout << "4"; }

private:
    A member_a;
};

class C : public B
{
public:
    C() { std::cout << "5"; }
    ~C() { std::cout << "6"; }

private:
    A member_a;
};

int main()
{
    C c;

    return 0;
}
