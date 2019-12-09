/**
 * Demonstrate a behavior of getting item from the container by lvalue reference then pop immediately
 * to see such item variable's lifetime.
 *
 * See https://stackoverflow.com/questions/6438086/iterator-invalidation-rules
 * to get the idea on whether or not iterator will be invalidated.
 *
 * In our testcases here for std::queue which derived from std::deque won't be invalidated
 * as we get from front().
 */
#include <iostream>
#include <queue>

struct Widget
{
    int a;

    Widget(int a_): a(a_) {}
    ~Widget() { std::cout << "dtor" << std::endl; }
};

int main()
{
    std::queue<Widget> q;
    q.emplace(Widget(1));
    const Widget& item = q.front();
    std::cout << item.a << std::endl;
    std::cout << "pop" << std::endl;
    q.pop();
    std::cout << item.a << std::endl;

    return 0;
}
