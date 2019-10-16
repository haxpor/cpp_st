/**
 * Demonstrate of validate the order of call in constructor/destructor methods for base, derived class and its
 * member variable.
 *
 * The order in which things will be initialized for a single class definition is as follows
 *  - BaseClass
 *      BaseClass Member 1
 *      BaseClass Member 2
 *      BaseClass Member 3
 *  - MyClass : BaseClass
 *      Member 1
 *      Member 2
 *      Member 3
 *
 *  Now for the order of construction
 *  - Constructor of MyClass object
 *      BaseClass Member 1
 *      BaseClass Member 2
 *      BaseClass Member 3
 *      BaseClass's Constructor method
 *      MyClass Member 1
 *      MyClass Member 2
 *      MyClass Member 3
 *      MyClass's Constructor method
 *  - Destructor of MyClass object
 *      MyClass's Destructor method
 *      MyClass Member 1
 *      MyClass Member 2
 *      MyClass Member 3
 *      BaseClass's Destructor method
 *      BaseClass Member 1
 *      BaseClass Member 2
 *      BaseClass Member 3
 *
 *  Try to run this program and see result for yourself.
 *
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

// global variable either it's static or not, will be contructed and initialized first
// before local variable inside function included main() but will be destructed last after
// all things
// Note: For ease of inspection for first time, you might want to comment out these two lines first
//       before uncomment them back again.
A a;
static B b;

int main()
{
    // see the top-most comment about construction/destruction order
    // if C derives from base class, it will go first up into the root base class which it derives
    // from then construct & initialize member variables first before calling its constructor method
    // then go down the chain to the down-most class which start the inheriting from other classes.
    // Whenever it destructs, it will goes reversely by starting from the class which starts inheritance.
    C c;

    return 0;
}
