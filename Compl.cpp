/**
 * Demonstrate the use of alternative operator representations
 * especially in this case use 'compl' instead of '~' for destructor function.
 *
 * See full list at https://en.cppreference.com/w/cpp/language/operator_alternative.
 */

#include <iostream>

class Widget
{
public:
    compl Widget()
    {
        std::cout << "Destructor" << std::endl;
    }
};

int main()
{
    Widget a;
    return 0;
}
