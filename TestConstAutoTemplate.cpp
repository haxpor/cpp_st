/**
 * Example to demonstrate that compiler is able to deduces the type from the receiving end of function (lvalue).
 * Template version
 */
#include <iostream>
#include <memory>

template <typename T>
class Widget
{
private:
    T n;
public:
    Widget(T n) : n(n) {}

    const auto getN() const -> const decltype((n)) & {
        return n;
    }

    auto getN() -> decltype((n)) & {
        return n;
    }
};

int main()
{
    Widget<double> w(10.5);

    std::cout << w.getN() << std::endl;

    // compiler deduce to use non-const version function
    auto& a = w.getN();
    a = 11;

    // compiler deduces whether it use const or non-const version function
    w.getN()++;

    // compiler duces to use non-const version function
    // but just that value cannot be modified
    const auto& b = w.getN();
    //b++;      // error, cannot do this

    std::cout << b << "(" << std::addressof(b) << ")" << std::endl;

    std::cout << a << "(" << std::addressof(a) << ")" << std::endl;
    std::cout << w.getN() << "(" << std::addressof(w.getN()) << ")" << std::endl;

    return 0;
}
