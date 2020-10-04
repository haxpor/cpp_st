/*
 * When there's no way to convert data type of arguments in braced initializer to the types in
 * std:initializer_list then it will fall back to normal overload resolution.
 */
#include <initializer_list>
#include <iostream>
#include <string>

struct Widget
{
    Widget(int n) { std::cout << "normal ctor called" << std::endl; }
    Widget(std::initializer_list<std::string> il) { std::cout << "initializer_list ctor called" << std::endl; }
};

int main()
{
    Widget w1(1.5); // this will call Widget(int)
    return 0;
}
