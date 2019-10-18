/**
 * Demonstrate how to use std::align but with placement new for struct/class object.
 *
 * Allocator in this case aims to support multiple types included scalar type, and struct/class type.
 * It has pre-defined fixed size to hold all data. It allocate new data in aligned manner via std::align.
 */

#include <iostream>
#include <memory>
#include <utility>
#include <iomanip>
#include <type_traits>

struct Widget
{
    int a;
    double b;

    Widget(): a(0), b(0.0) {}
    Widget(int a, double b): a(a), b(b) {}
    ~Widget() { std::cout << "dtor Widget [" << a << ", " << b << "]\n"; }
};

// Note: This is an improved allocator version from Align.cpp.
//
// MyAllocator supports multiple different type either scalar or struct/class type
// allocated in aligned manner within a pre-defined fixed size memory space on stack.
//
// Caveat
//  - as this allocator supports multiple different type on the whim, and no support to keep track
//    of which type at which indexed-location in its backend data. Users have to call destructor
//    method manually via ->~T(). This can be solved by providing just one type for allocator.
//    See AlignedStorage.cpp for solution on this.
template <std::size_t N>
struct MyAllocator
{
    // actual backend data
    char data[N];
    // current usable data pointer
    void* p;
    // current size of usable data in this allocator
    std::size_t sz;

    // initialize pointer pointing to the beginning of data, and sz to maximum of size available
    MyAllocator(): p(data), sz(N) {}

    // template function for aligned memory allocation
    template <typename T, std::size_t a = alignof(T), typename ...Args>
    T* aligned_alloc(Args&&... args)
    {
        if (std::align(a, sizeof(T), p, sz))
        {
            // reinterpret our desire pointer to starting location of the usable address for user's data
            T* result = reinterpret_cast<T*>(p);
            // increment the size that allocator has used
            // as std::align already did its work via aligned allocate the memory, and its return
            // pointer points at the starting location of usable address, thus we just increment by
            // its type via sizeof(T)
            p = (char*)p + sizeof(T);
            // usable size decremented
            sz -= sizeof(T);
            // construct the object from returned aligned memory space
            // what returned from the following line is the same as 'result'
            new (result) T(std::forward<Args>(args)...);
            // return usable pointer back to user
            return result;
        }
        // space provided is too small
        return nullptr;
    }
};

int main()
{
    // fixed size memory space on stack
    MyAllocator<64> allocator;

    // note: p1 is not allocated on heap, it is a pointer which points to starting address of
    // char type which we allocates from within allocator
    char* p1 = allocator.aligned_alloc<char>();

    // notice the memory address of aligned memory
    // it is aligned when such memory address is divisible by the alignment number
    std::cout << "allocated p1 at " << (void*)p1 << " [size: " << sizeof(char) << "]\n";
    std::cout << "usable size of allocator: " << allocator.sz << '\n';

    char* p2 = allocator.aligned_alloc<char, 'a'>();
    std::cout << "allocated p2 at " << (void*)p2 << " [size: " << sizeof(char) << "]\n";
    std::cout << "usable size of allocator: " << allocator.sz << '\n';
    std::cout << *p2 << '\n';

    Widget* p3 = allocator.aligned_alloc<Widget>(50, 65.21);
    std::cout << "allocated p3 " << (Widget*)p3 << " [size: " << sizeof(Widget) << "]\n";
    std::cout << "usable size of allocator: " << allocator.sz << '\n';
    std::cout << p3->a << ", " << p3->b << '\n';

    Widget* p4 = allocator.aligned_alloc<Widget>();
    if (p4 == nullptr)
    {
        std::cout << "Not enough space left to allocate more object\n";
    }

    // due to caveat of MyAllocator, we manually call its destructor method
    p3->~Widget();

    std::cout.flush();

    return 0;
}
