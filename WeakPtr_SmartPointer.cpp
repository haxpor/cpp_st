/**
 * Demonstrate usage of std::weak_ptr.
 */

#include <iostream>
#include <memory>

struct Widget
{
    int a;

    Widget(): a(0)
    {
        std::cout << "ctor a(" << a << ")" << std::endl;
    }

    Widget(const int a): a(a)
    {
        std::cout << "ctor a(" << a << ")" << std::endl;
    }

    ~Widget()
    {
        std::cout << "dtor a(" << a << ")" << std::endl;
    }
};

// -- Declaration/Definition to demonstrate cyclic reference problem solved by using std::weak_ptr -- //
struct B;
struct A
{
    int num;
    std::weak_ptr<B> another;

    A(): num(10)
    {
        std::cout << "ctor A" << std::endl;
    }
    
    ~A()
    {
        std::cout << "dtor A" << std::endl;
    }
};

struct B
{
    int num;
    std::weak_ptr<A> another;

    B(): num(20)
    {
        std::cout << "ctor B" << std::endl;
    }
    
    ~B()
    {
        std::cout << "dtor B" << std::endl;
    }

    void PrintAnotherVal() const
    {
        if (!another.expired())
        {
            // it needs to lock to access managed object
            std::cout << another.lock()->num << std::endl;
        }
    }
};
// -- end of section -- //

static void Expired(const std::weak_ptr<Widget>& w)
{
    if (w.expired())
    {
        std::cout << "w is expired" << std::endl;
    }
    else
    {
        std::cout << "w is not expired" << std::endl;
    }
}

template <typename T>
static void SameSharedPtr(const std::weak_ptr<T>& w, const std::shared_ptr<T>& s)
{
    if (!w.expired())
    {
        auto sharedPtr = w.lock();

        // compare if shared_ptr from weak_ptr is the same as s
        bool r = sharedPtr == s;

        // just to get address of managed object from shared_ptr, not necessary for main operation
        // a.get() == b.get() is exactly what happened in operator== of shared_ptr thus
        // the line above of result for r is sufficient.
        auto s1 = sharedPtr.get();
        auto s2 = s.get();
        // for s1 and s2, it still need another dereference because managed object is a pointer, thus
        // it needs another dereferenced to get to the actual pointed data to get a proper memory address
        // to print for comparison
        std::cout << std::boolalpha << "weak_ptr's lock() of managed object at " << std::addressof(*s1)
                  << " is the same as shared_ptr of managed object at "  << std::addressof(*s2)
                  << " ? " << r << std::endl;
    }
}

int main()
{
    // to use weak_ptr, at least whole thing should be started with shared_ptr
    auto s = std::make_shared<Widget>();

    // create weak_ptr from shared_ptr
    std::weak_ptr<Widget> w1(s);

    // use operator=, after this w2 will share the same managed object as well as reference count
    std::weak_ptr<Widget> w2 = w1;

    // create weak_ptr that managed empty object
    std::weak_ptr<Widget> w3;

    // check whether managed object is still valid
    // Valid in this case doesn't mean that managed object is destructed already, but it's imminent,
    // anyway it means that number of shared_ptr sharing the same managed object.
    {
        std::shared_ptr<Widget> s = std::make_shared<Widget>(1);

        // now make w3 shares the same managed object with s
        w3 = s;

        Expired(w3);
    }
    Expired(w3);

    // cyclic reference demonstration solved by using std::weak_ptr
    auto csA = std::make_shared<A>();
    auto csB = std::make_shared<B>();

    // make weak_ptr shares managed object with shared_ptr
    // forming cyclic reference here
    csA->another = csB;
    csB->another = csA;

    // ref-count for both should be 1
    std::cout << "csA ref-count: " << csA.use_count() << std::endl;
    std::cout << "csB ref-count: " << csB.use_count() << std::endl;

    csB->PrintAnotherVal();

    // check whether weak_ptr::lock() will get the same memory address of pointed shared_ptr
    // note: no need to specify template parameters as it can deduce from function's arguments
    SameSharedPtr(csB->another, csA);
    SameSharedPtr(csA->another, csB);

    return 0;
}
