/**
 * Demonstrate function call involving using brace initialization with assignment operator function.
 * To see if assignment operator function is called or not even though it uses brace initialization.
 *
 * Please excuse my term, it's actually officially called list initialization :)
 *
 * Note: If test by yourself and operator= isn't called as you expect, remember that it is meant to
 *       be called on behalf of lvalue reference.
 */
#include <iostream>
#include <initializer_list>
#include <type_traits>

class Widget
{
public:
    Widget(): Widget(10) { std::cout << "ctor1" << std::endl; }
    Widget(int n): n(n)
    {
        std::cout << "ctor2" << std::endl;
    }

    Widget(const Widget& rhs): n(rhs.n)
    {
        std::cout << "ctor3" << std::endl;
    }

    // std::initializer_list takes only one type
    // for multiple types, use variadic templates
    Widget(std::initializer_list<int> list): n(list.size())
    {
        std::cout << "ctor4 ";
        for (auto it=list.begin(); it!=list.end(); ++it)
        {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
    }

    Widget& operator=(std::initializer_list<int> list)
    {
        std::cout << "operator= (std::initializer_list<int>) ";
        for (auto it=list.begin(); it!=list.end(); ++it)
        {
            std::cout << *it << " ";
        }
        std::cout << std::endl;
        return *this;
    }

    Widget& operator=(const Widget& rhs)
    {
        std::cout << "operator= called (const Widget&)" << std::endl;
        n = rhs.n;
        return *this;
    }

    Widget& operator=(Widget rhs)
    {
        std::cout << "operator= called (Widget)" << std::endl;
        n = rhs.n;
        return *this;
    }

    Widget& operator=(Widget&& rhs)
    {
        std::cout << "operator= called (Widget&& rhs)" << std::endl;
        n = rhs.n;
        return *this;
    }

private:
    int n;
};

int main()
{
    Widget n { 1, 5, 10 };
    Widget n2 = { 1, 10, 20 };
    Widget n3 = Widget(1);
    n3 = { 1, 10, 20};
    
    return 0;
}
