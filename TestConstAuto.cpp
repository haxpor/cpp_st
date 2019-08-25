/**
 * Example to demonstrate that compiler is able to deduces the type from the receiving end of function (lvalue).
 */
#include <iostream>
#include <memory>

class Widget
{
public:
    Widget(int n) : n(n) {}

    const int& getInt() const {
        return n;
    }

    int& getInt() {
        return n;
    }

private:
    int n;
};

int main()
{
    Widget w(10);

    std::cout << w.getInt() << std::endl;

    // compiler deduce to use non-const version function
    int& a = w.getInt();
    a = 11;

    // compiler deduces whether it use const or non-const version function
    w.getInt()++;

    // compiler duces to use non-const version function
    // but just that value cannot be modified
    const auto& b = w.getInt();
    //b--;      // cannot do this

    std::cout << b << "(" << std::addressof(b) << ")" << std::endl;

    std::cout << a << "(" << std::addressof(a) << ")" << std::endl;
    std::cout << w.getInt() << "(" << std::addressof(w.getInt()) << ")" << std::endl;

    return 0;
}
