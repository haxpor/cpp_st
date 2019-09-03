/**
 * Demonstrate usage of friend function
 */

#include <iostream>

class Widget
{
public:
    // force users to use Widget(const int a) constructor function
    Widget() = delete;
    Widget(const int a) : a(a) { }

    // remember that friend function is not member-function
    // its declaration and definition can live inside the class scope.
    //
    // Declare friend function when we want it to be able to access private, or protected
    // member variables or functions of target class.
    //
    // Thus its function's argument mostly need object input of class it will be interact with.
    friend void Dummy(Widget& obj1, Widget& obj2)
    {
        std::cout << "obj1.a = " << obj1.a << std::endl;
        std::cout << "obj2.a = " << obj2.a << std::endl;
    }

private:
    int a;
};

int main()
{
    Widget a(1);
    Widget b(2);

    Dummy(a, b);
    
    return 0;
}
