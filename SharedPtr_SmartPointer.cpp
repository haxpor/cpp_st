/*
 * Demonstrate usage of std::shared_ptr
 */

#include <iostream>
#include <memory>

struct Widget
{
    int a;

    Widget(): a(0)
    {
        std::cout << "ctor(1) - a(" << a << ")" << std::endl;
    }

    Widget(const int a): a(a)
    {
        std::cout << "ctor(2) - a(" << a << ")" << std::endl;
    }

    ~Widget()
    {
        std::cout << "dtor - a(" << a << ")" << std::endl;
    }
};

static void Deleter(Widget* p)
{
    std::cout << "Global Deleter for p at address " << std::addressof(p) << std::endl;
    delete[] p;
    std::cout << "Finished" << std::endl;
}

int main()
{
    // only variable on heap to be added to be managed by shared_ptr (or other smart pointers)
    //int a = 10;
    //std::shared_ptr<int> s0(&a);
    
    std::shared_ptr<Widget> s1( new Widget(1) );
    auto s2 = std::make_shared<Widget>(2);

    // multiple shared_ptr points to the same resource, it's OK
    // reason: multiple shared_ptr share the same reference count, hence belong to the same group
    std::shared_ptr<Widget> s3( new Widget(2) );
    std::cout << "ref count: " << s3.use_count() << std::endl;

    std::shared_ptr<Widget> s4(s3);
    std::cout << "ref count: " << s4.use_count() << std::endl;

    // the following section is NOT FINE!
    // don't create shared_ptr from nake pointer
    // note: you can enable the code, then look at console, it has independent ref count, and
    // one of shared_ptr destroys itself un-properly (or say it should not be destroyed)
#if 0
    Widget* w = new Widget(3);
    std::shared_ptr<Widget> s3_(w);
    std::cout << "_ref count: " << s3_.use_count() << std::endl;

    std::shared_ptr<Widget> s4_(w);
    std::cout << "_ref count: " << s4_.use_count() << std::endl;
#else
    // but the following is ok
    // from previous code block, do this instead
    // from now on, for safety, don't ever touch w again.
    Widget* w = new Widget(3);

    std::shared_ptr<Widget> s3_(w);
    std::cout << "_ref count: " << s3_.use_count() << std::endl;

    std::shared_ptr<Widget> s4_(s3_);
    std::cout << "_ref count: " << s4_.use_count() << std::endl;
#endif

    // INCORRECT use to create shared_ptr for array of managed objects
    // although result might looks good, but actually it's UB, don't do it.
    //auto s5 = std::shared_ptr<Widget[]>(new Widget[5]);
    
    // shared_ptr to array of objects for managed object
    // note:: std::make_shared cannot be used in this case as it doesn't accept custom deleter
    auto s6 = std::shared_ptr<Widget[]>(new Widget[5], std::default_delete<Widget[]>());

    // or supply deleter with lambda function
    // you can try to peek into bits/unique_ptr.h (as for GCC on Ubuntu 18.04) to see its function's
    // signature and its definition.
    auto s7 = std::shared_ptr<Widget[]>(new Widget[2], [](Widget* p) { 
            std::cout << "Deleter via Lambda function of p at address " << std::addressof(p) << std::endl;
            delete[] p;
            std::cout << "Finished" << std::endl;
    });

    // or supply with global function
    auto s8 = std::shared_ptr<Widget[]>(new Widget[2], Deleter);

    // use operator bool to check whether it has managed object in manage (or *this or get() != nullptr)
    if (s8)
    {
        std::cout << "s8 has managed object" << std::endl;
    }

    return 0;
}
