/**
 * Event with non-empty constructor, or empty constructor available, it won't help compiler to
 * treat parentheses initialization as non-function declaration.
 */
#include <iostream>

struct Widget
{
    int a;

    // even with empty constructor, it won't help compiler to regard "Widget w();" as
    // constructor method call
    Widget() { }
    // event with availability of non-empty constructor, it won't help as well
    Widget(int i): a(i) { }
};

int main()
{
    Widget w();
    std::cout << typeid(w).name() << std::endl;     // demangle the output with c++filt to get "Widget ()"
                                                    // indicating that it is function
    //w.a = 10;     // compile error if uncomment, as compiler didn't treat w as class
    return 0;
}
