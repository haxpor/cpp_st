// -- tested with g++ -std=c++17 -Wall -Wextra
// Wrapper or smart pointer is just taking benefit from its life-time management via dtor to clean up
// pointer.
#include <iostream>
#include <cstddef>

struct Widget
{
    Widget()
    {
        std::cout << "ctor" << std::endl;
    }
    ~Widget()
    {
        std::cout << "dtor" << std::endl;
    }
};

template <typename T>
struct WrapperCleanup
{
    WrapperCleanup() = default;

    WrapperCleanup(T* ptr_) : ptr(ptr_)
    {
        std::cout << "WrapperCleanup ctor" << std::endl;
    }

    ~WrapperCleanup()
    {
        std::cout << "WrapperCleanup dtor" << std::endl;
        delete ptr;
        ptr = nullptr;
    }

    // might be more efficient to implement via swap
    WrapperCleanup& operator=(std::nullptr_t)
    {
        delete ptr;
        ptr = nullptr;
        return *this;
    }

private:
    T* ptr = nullptr;
};

int main()
{
    WrapperCleanup<Widget> ptr (new Widget());
    ptr = nullptr;
    return 0;
}
