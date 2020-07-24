/**
 * Demonstrate the automatic call of default constructor in class.
 */
#include <iostream>

class WidgetA
{
public:
    WidgetA()
    {
        std::cout << "WidgetA\n";
    }
};

class WidgetB : WidgetA
{
public:
    WidgetB() = default;
};

class WidgetC : WidgetB
{
public:
    WidgetC() = default;
};

int main()
{
    WidgetC b;
    return 0;
}
