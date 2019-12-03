#pragma once

#include <iostream>

/// This type of singleton class doesn't prohibit a derived class to extend.
/// Note that Singleton's contructor and destructor will be called whenever we create an instance
/// from it. But mostly for this case, we just want to make use of Singleton::GetInstance() to get
/// its managed input type.
template <typename T>
class Singleton
{
public:
    virtual ~Singleton()
    {
        std::cout << "dtor Singleton\n";
    }

    Singleton(const Singleton&) = delete;
    Singleton(Singleton&&) = delete;
    Singleton& operator=(const Singleton&) = delete;
    Singleton& operator=(Singleton&&) = delete;

    static const T& GetInstance()
    {
        static T instance;
        return instance;
    }

private:
    Singleton()
    {
        std::cout << "ctor Singleton\n";
    }
};
