// std::shared_ptr and std::unique_ptr has contructor which accepts std::nullptr_t
// in which compiler can convert 0 or NULL into std::nullptr_t without problem.
// That's why it works.
//
// Solve it by having template to deduce the type of argument before using it as function's argument
// will help differentiate the case of correct data type to be used with such function.
//
// Taken the code example from Effective C++ - Item 8
#include <memory>

class Widget {};

int f1(std::shared_ptr<Widget> p) { return 1; }
float f2(std::unique_ptr<Widget> p) { return 1.0f; }
double f3(Widget* p) { return 1.0; }

template<typename FuncType, typename Arg>
decltype(auto) fTmp(FuncType func, Arg arg)
{
    return func(arg);
}

int main()
{
    auto r1 = f1(0);
    auto r2 = f2(NULL);
    auto r3 = f3(nullptr);

    //auto r4 = fTmp(f1, 0);      // GCC compile error: "could not convert 'arg' from 'int' to 'std::shared_ptr<Widget>'"
    //auto r5 = fTmp(f2, NULL);     // GCC compile error: "could not convert 'arg' from 'long int' to 'std::unique_ptr<Widget>'"
    auto r6 = fTmp(f3, nullptr);
    return 0;
}
