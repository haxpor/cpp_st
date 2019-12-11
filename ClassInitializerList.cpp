/**
 * Validate the order of calling initializer list of class and as its member variables.
 *
 * If we define the member variable within the class, if there is no initialization via
 * initializer list for such variable then it will call default constructor, reversely it will
 * call such specific constructor. The order is the same for both.
 *
 * See ConstructorDestructor.cpp as well for order of initialization for whole class.
 */

#include <iostream>

struct SubWidget
{
    SubWidget()
    {
        std::cout << "SubWidget - ctor" << std::endl;
    }

    SubWidget(int a)
    {
        std::cout << "SubWidget - ctor(" << a << ")" << std::endl;
    }
};

class WidgetA
{
public:
    WidgetA()
        : sw(1)
    {
        std::cout << "Widget - ctor" << std::endl;
    }
private:
    SubWidget sw;
};

class WidgetB
{
public:
    WidgetB()
    {
        std::cout << "Widget - ctor" << std::endl;
    }
private:
    SubWidget sw;
};

int main()
{
    WidgetA a;
    WidgetB b;
    return 0;
}
