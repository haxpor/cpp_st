/**
 * Demonstrate an interesting rule which informally says that "Rvalue reference doesn't have a name".
 *
 * This question on SO triggers me to conduct a test bed: https://stackoverflow.com/questions/58276682/why-is-this-variable-considered-an-lvalue.
 * In short, even the overloaded function has a signature which accepts rvalue reference, and inside it passes
 * such variable into another function call which accepts rvalue reference the same. It turns out
 * it sends lvalue reference!
 *
 * So this comment sums it up the best: https://stackoverflow.com/questions/32620750/why-are-rvalues-references-variables-not-rvalue#comment53091770_32620750
 * which says "Rvalues don't have names. What you have is a name for something that you're confident is safe to move from".
 */
#include <iostream>
#include <algorithm>

class A
{
public:
    A() {};
    A(A& a) = delete;
    A(A&& a) { };
};

static void foo(A&& a)
{
    // uncomment the following line to see the effect of compile error as it attempts to call
    // A(A& a) = delete overloaded constructor
    //A myObj(std::move(a));

    A myObj(std::move(a));
}

int main()
{
    foo(A());
    return 0;
}
