/**
 * Demonstrate the use of Deduction guides to relay type construction into template-based construction
 *
 * Features available in C++17
 *
 * Notice:
 * - the use of "using T::operator()...; is to bring in T::operator() into overloaded
 *   type scope removing ambiguity during template type deduction. I don't think
 *   it is about fully qualified name.
 * - "struct overloaded : T" without inheritance accessibility because its default
 *   is public for struct.
 * - brace initializer list is specifically used alongside Deduction guides (not use parenthesis)
 */
#include <iostream>

template <typename... T>
struct overloaded : T... { using T::operator()...; };

// Deduction guides template
template <typename... T>
overloaded(T...) -> overloaded<T...>;

struct Base
{
    void operator()() {
        std::cout << "something" << std::endl;
    }
};

int main()
{
    auto t1 = overloaded{
        []() { std::cout << "no parameters" << std::endl;},
        [](int arg) { std::cout << "value is " << arg << std::endl;}
    };
    auto t2 = overloaded{Base()};

    t1();
    t1(2);
    t2();
    return 0;
}
