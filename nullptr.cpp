// std::shared_ptr and std::unique_ptr has contructor which accepts std::nullptr_t
// in which compiler can convert 0 or NULL into std::nullptr_t without problem.
// That's why it works.
#include <memory>

class Widget {};

int f1(std::shared_ptr<Widget> p) { return 1; }
float f2(std::unique_ptr<Widget> p) { return 1.0; }

int main()
{
    auto r1 = f1(0);
    auto r2 = f2(NULL);
    return 0;
}
