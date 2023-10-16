/**
Demonstrate that getting enum class from raw value
doesn't bound, and there is potential bug.

g++ -std=c++17 -Wall -Wextra
**/

#include <iostream>

enum class MyEnum : int
{
    Type1,
    Type2
};

int main()
{
    auto e = static_cast<MyEnum>(4);
    if (e == MyEnum::Type1)
        std::cout << "Type1" << std::endl;
    else if (e == MyEnum::Type2)
        std::cout << "Type2" << std::endl;
    else
        std::cout << "outside of the range" << std::endl;

	return 0;
}
