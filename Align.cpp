/**
 * Demonstrate how to use std::align
 *
 * Man page of std::align has example code of memory allocator.
 * The following just follows such implementation, but provided more code comment along the step, and
 * slight modification.
 * 
 * There is an interesting notice for std::align and std::aligned_storage.
 * - std::align is an operation to return starting location of aligned memory from the input buffer which
 * can be either on stack, or heap.
 *
 * - std::aligned_storage is data structure holding aligned memory space on **stack**.
 */

#include <iostream>
#include <memory>

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
    template <typename T>
    T* aligned_alloc(std::size_t a = alignof(T))
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
    if (p1)
        *p1 = 'a';

    // notice the memory address of aligned memory
    // it is aligned when such memory address is divisible by the alignment number
    std::cout << "allocated p1 at " << (void*)p1 << '\n';
    std::cout << "usable size of allocator: " << allocator.sz << '\n';

    char* p2 = allocator.aligned_alloc<char>(8);
    std::cout << "allocated p2 at " << (void*)p2 << '\n';
    std::cout << "usable size of allocator: " << allocator.sz << '\n';

    int* p3 = allocator.aligned_alloc<int>();
    std::cout << "allocated p3 at " << (void*)p3 << '\n';
    std::cout << "usable size of allocator: " << allocator.sz << '\n';

    int* p4 = allocator.aligned_alloc<int>(16);
    std::cout << "allocated p4 at " << (void*)p4 << '\n';
    std::cout << "usable size of allocator: " << allocator.sz << '\n';

    double* p5 = allocator.aligned_alloc<double>();
    std::cout << "allocated p5 at " << (void*)p5 << '\n';
    std::cout << "usable size of allocator: " << allocator.sz << '\n';

    return 0;
}
