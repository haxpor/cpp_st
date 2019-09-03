/**
 * Demonstrate casting using
 *  - static_cast<> -> do a compile-time based casting to the target
 *  - dynamic_cast<> -> rely on run-time check whether such type can be casted to the target
 *  - reinterpret_cast<> -> rawly interpret from one type to another without modification
 *  - const_cast<> -> to cast away const ness (only this operator can do it)
 *
 * When compiled, you will see compile error as following
 *
 * Castings.cpp:38:7: warning: direct base ‘A’ inaccessible in ‘Derived’ due to ambiguity
 * class Derived : public A, public B
 *
 * don't worry about the error above as we intend to do multiple inhiritance here for studying purpose.
 *
 * Line comments uses #if 0 and #endif pair for clearer to see in code. Change 0 to 1 to enable such
 * code section.
 */

#include <iostream>

struct Widget
{
    int a;

    Widget() : a(0) {}
    Widget(int a) : a(a) {}
};

struct NotRelatedWidget
{
    int a;
};

// -- for testing casting --
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
// -- end section --

int main()
{
    Widget a;
    const Widget b(1);
    const Widget* ptr = &b;

    // this is fine
    static_cast<const Widget>(a);           

    // this line is compile error, cannot modify const object
#if 0
    static_cast<const Widget>(a).a = 10;  
#endif
    
    // although no error, but static_cast<> cannot cast constness away
    // if uncomment this line, then compile error occurs
#if 0
    static_cast<Widget>(b).a = 10;                                                    
#endif
    
    // these three lines cast away constness. CANNOT DO IT!
    // result in compile error
#if 0
    static_cast<Widget*>(ptr);
    reinterpret_cast<Widget*>(ptr);
    dynamic_cast<Widget*>(ptr);
#endif
    
    // to cast away constness, use const_cast
    Widget* cPtr = const_cast<Widget*>(ptr);
    cPtr->a = 20;
    std::cout << "cPtr->a = " << cPtr->a << std::endl;

    // casting to un-related type won't be allowed, compiler error here
    // as static_cast is based on compile-time for this line (anyway it can be runtime in case it really needs)
    // note: uncomment this then compile to see the effect
#if 0
    static_cast<NotRelatedWidget>(a);
#endif

    // testing down-cast from base to derived class
    Derived* dPtr = new Derived();
#if 0
    // ambiguous, not OK
    static_cast<A*>(dPtr);
    dynamic_cast<A*>(dPtr);
#endif

    // this is fine, we know what we're doing
    reinterpret_cast<A*>(dPtr);

    return 0;
}
