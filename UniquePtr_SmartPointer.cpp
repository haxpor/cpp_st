/**
 * Demonstrate usage of std::unique_ptr smart pointer.
 *
 * This program uses std::make_unique which is available since c++14.
 * Compile it with `g++ -std=c++14 ...`.
 */

#include <iostream>
#include <memory>
#include <vector>
#include <algorithm>

class Widget
{
public:
    Widget(): a(0)
    {
        std::cout << "Widget - ctor1" << std::endl;
    }
    Widget(const int a): a(a)
    {
        std::cout << "Widget - ctor2" << std::endl;
    }
    ~Widget()
    {
        std::cout << "Widget - dtor(" << a << ")" << std::endl;
    }

    const int GetA() const
    {
        return a;
    }

    void SetA(const int a)
    {
        this->a = a;
    }
    
private:
    int a;
};

int main()
{
    std::cout << "sizeof(std::unique_ptr<Widget>) = " << sizeof(std::unique_ptr<Widget>) << std::endl;

    // support both single or array of objects as managed objects
    std::unique_ptr<Widget> u1( new Widget(1) );
    std::unique_ptr<Widget[]> u2( new Widget[5] );

    Widget* w = new Widget(3);
    std::unique_ptr<Widget> u3( w );

    std::cout << w->GetA() << std::endl;
    std::cout << u3->GetA() << std::endl;

    u3.reset();

    // should not call any methods from managed object, or smart pointer again
    //std::cout << w->GetA() << std::endl;
    //std::cout << u3->GetA() << std::endl;
    
    // access element in array of objects of unique_ptr
    u2[0].SetA(0);
    u2[1].SetA(1);
    u2[2].SetA(2);
    u2[3].SetA(3);
    u2[4].SetA(4);

    for (int i=0; i<5; ++i)
    {
        std::cout << "u2[" << i << "] = " << u2[i].GetA() << std::endl;
    }

    // move (to transfer ownership)
    std::unique_ptr<Widget> u4 = std::move(u1);
    if (u4.get() == nullptr)
    {
        std::cout << "u4.get() is nullptr" << std::endl;
    }
    if (u1.get() == nullptr)
    {
        std::cout << "u1.get() is nullptr" << std::endl;
    }

    // move (of array of objects type, to transfer ownership)
    std::unique_ptr<Widget[]> u5 = std::move(u2);
    std::cout << "u5[4] = " << u5[4].GetA() << std::endl;
    if (u2.get() == nullptr)
    {
        std::cout << "u2.get() is nullptr" << std::endl;
    }

    // use std::make_unique
    // note: available only since C++14
    std::unique_ptr<Widget> u6 = std::make_unique<Widget>(6);

    return 0;
}
