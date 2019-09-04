/**
 * Demonstrate using of placement-new to construct multiple of objects on already allocated block
 * of memory.
 *
 * Do it in 2 ways
 *  1. By hands using `new` and `new()` (placement-new)
 *  2. using std::allocator
 */

#include <iostream>
#include <memory>

class Widget
{
public:
    Widget() = delete;
    Widget(const int a): a(a)
    {
        std::cout << "Widget ctor" << std::endl;
    }
    ~Widget()
    {
        std::cout << "Wdiget dtor" << std::endl;
    }
    int a;
};

int main()
{
    // 1. allocate byte-array memory chunk
    char* buffer = new char[sizeof(Widget)];
    // as new () (placement-new) also return void* thus we need std::string* at receiving end
    Widget* w = new (buffer) Widget(1);
    std::cout << w->a << std::endl;
    // call directly to class's destructor, but not call delete or delete[]
    w->~Widget();
    delete buffer;

    // 2. using std::allocator
    std::allocator<std::string> a;
    std::string* s = a.allocate(sizeof(std::string));
    a.construct(s, "Hello2"); 
    std::cout << *s << std::endl;
    a.destroy(s);
    a.deallocate(s, sizeof(std::string));

    return 0;
}
