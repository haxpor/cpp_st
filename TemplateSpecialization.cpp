/**
 * Demonstrate template specialization with constant integer as template parameter.
 */

#include <iostream>

// enum class should be preferred way in defining enum in c++
// to minimizing the risk of bugs of type conversion
// see https://stackoverflow.com/a/18335862/571227
enum class MyEnum { Enum1, Enum2, Enum3 };

template <typename E, const int I> struct EnumTraits { };
template <> struct EnumTraits<MyEnum, 1>
{
    constexpr static const char* name = "Enum1";
};

template <> struct EnumTraits<MyEnum, 2>
{
    constexpr static const char* name = "Enum2";
};

template <> struct EnumTraits<MyEnum, 3>
{
    constexpr static const char* name = "Enum3";
};

int main()
{
    std::cout << EnumTraits<MyEnum,1>::name << std::endl;
    std::cout << EnumTraits<MyEnum,2>::name << std::endl;
    std::cout << EnumTraits<MyEnum,3>::name << std::endl;
    return 0;
}
