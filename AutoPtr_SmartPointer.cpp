/**
 * Demonstrate usage of auto_ptr
 *
 * When compiled, you might encounter 'decprecated' warning of using auto_ptr itself.
 * No need to worry, this is for studying purpose. But note, in production code, there's better
 * smart pointer to choose and use than auto_ptr.
 */

#include <iostream>
#include <memory>

class Widget
{
    public:
        Widget() = delete;
        Widget(const int a): a(a) {} ;
        ~Widget()
        {
            std::cout << "dtor for .a=" << a << std::endl;
        }

        inline const int GetA() const
        {
            return a;
        }

        inline void SetA(const int a)
        {
            this->a = a;
        }
    private:
        int a;
};

template <typename T>
static void Func(const std::auto_ptr<T>& ptr)
{
    std::cout << "Called from Func()" << std::endl;
    std::cout << "Original value: " << ptr->GetA() << std::endl;
    ptr->SetA(5);
    std::cout << "Changed to: " << ptr->GetA() << std::endl;
}

template <typename T>
static void Func2(std::auto_ptr<T> ptr)
{
    std::cout << "Called from Func2()" << std::endl;
    std::cout << "Original value: " << ptr->GetA() << std::endl;
    ptr->SetA(6);
    std::cout << "Changed to: " << ptr->GetA() << std::endl;
}

static void FThrow() noexcept(false)
{
    throw "I gonna throw";
}

int main()
{
    std::auto_ptr<Widget> p(new Widget(1));
    std::cout << "p->GetA() = " << p->GetA() << std::endl;
    // transfer ownership to function's argument as it will always be executed for its
    // assignment operator function (calling reset(release())) no further operation will be done
    // when p is out of scope
    Func(p);
    std::cout << "After calling Func()" << std::endl << std::endl;

    // whenever exception is throw, it's still fine to get destroyed
    try
    {
        std::auto_ptr<Widget> p2(new Widget(2));
        FThrow();
        std::cout << "p2.GetA() = " << p2->GetA() << std::endl;
    }
    catch (...)
    {
        std::cout << "Something went wrong" << std::endl;
    }

    std::cout << std::endl;

    // test how it handle when we pass auto_ptr into function
    std::auto_ptr<Widget> p3(new Widget(3));
    Func2(p3);
    std::cout << "After calling Func2()" << std::endl;
    // test if managed object is still there?
    std::cout << (p3.get() != nullptr ? "OK" : "NOT OK") << std::endl;

    // test * dereferencing
    std::auto_ptr<Widget> p4(new Widget(4));
    // it returns reference to managed object
    std::cout << (*p4).GetA() << std::endl;
    return 0;
}
