/**
 * Demonstrate usage of type-casting operator.
 *
 * Seen this one used in std::ref (which uses std::reference_wrapper which defines type-casting operator function).
 * In short, type-casting operator will have a chance to be invoked at the implicit conversion state,
 * only when there is no direct-initialization.
 *
 * Read more about type-casting operator at https://en.cppreference.com/w/cpp/language/cast_operator.
 */

#include <iostream>
#include <utility>

template <typename T>
class Widget
{
public:
    template <typename... Args>
    Widget(Args&&... args): a(std::forward<Args>(args)...) { }

    // type-casting operator
    // this returns reference of the backing member variable
    operator T&() noexcept
    {
        std::cout << "type-casting operator called\n";
        return a;
    }

    T& get()
    {
        return a;
    }

private:
    T a;
};

struct Data
{
    int a;
    int b;

    Data(int a, int b): a(a), b(b) { }
};

int main()
{
    // primitive data type as managed object
    {
        Widget<int> a(10);

        // invoke implicit conversion
        // this returns the reference to backing data store managed by Widget
        int& casted_a = a;
        std::cout << casted_a << "\n";

        // this will modified original managed object's value as well
        casted_a = 11;
        std::cout << "casted_a = " << casted_a << "\n";
        std::cout << "original = " << a.get() << "\n";
        std::cout << "same? = " << std::boolalpha << (std::addressof(casted_a) == std::addressof(a.get())) << "\n";
    }

    std::cout << "\n";

    // class type as managed object
    {
        Widget<Data> a(1, 2);
        Data& casted_a = a;
        std::cout << casted_a.a << ", " << casted_a.b << "\n";
        
        casted_a.a = 3;
        casted_a.b = 4;

        std::cout << "casted_a = " << casted_a.a << ", " << casted_a.b << "\n";
        std::cout << "original = " << a.get().a << ", " << a.get().b << "\n";
        std::cout << "same? = " << std::boolalpha << (std::addressof(casted_a) == std::addressof(a.get())) << "\n";
    }
    return 0;
}
