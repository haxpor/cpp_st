/**
 * Demonstrate how to implement modern singleton class
 * in template class.
 */

#include "Singleton.h"

// define a class which will be wrapped by Singleton class to make
// it a singleton.
// Just go on and implement MyManager class in a perspective of it being
// just a normal class, and not to think about singleton. Singleton<T> will
// do things for us.
class MyManager
{
public:
    MyManager()
    {
        std::cout << "ctor MyManager" << std::endl;
    }
    ~MyManager()
    {
        std::cout << "dtor MyManager" << std::endl;
    }

    void PrintNum(int n) const
    {
        std::cout << "Something: " << n << std::endl;
    }
};

// call AutoDestroy() then assign it to variable to live in the
// selected scope. Whenever it goes out of scope, it will delete
// our singleton for us.
//
// no need to interact with this variable any further, we can just
// leave it here.
auto mmsingleton = Singleton<MyManager>::AutoDestroy();

int main()
{
    // get underlying singleton object wrapped by Singleton for use in the current scope
    auto& m1 = Singleton<MyManager>::GetInstance();
    auto& m2 = Singleton<MyManager>::GetInstance();

    if (std::addressof(m1) == std::addressof(m2))
        std::cout << "m1 == m2? [true]" << std::endl;
    if (std::addressof(m1) == std::addressof(Singleton<MyManager>::GetInstance()))
        std::cout << "m1 == Singleton<MyManager>::GetInstance()? [true]" << std::endl;
    if (std::addressof(m2) == std::addressof(Singleton<MyManager>::GetInstance()))
        std::cout << "m2 == Singleton<MyManager>::GetInstance()? [true]" << std::endl;

    Singleton<MyManager>::GetInstance().PrintNum(1);
    m1.PrintNum(2);
    m2.PrintNum(3);

    return 0;
}
