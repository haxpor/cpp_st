/*
 * Demonstrate why member function pointer needs 2 bytes
 * constrasting to normal pointer which occupies just 1 byte.
 *
 * The root inspiration of this demonstration is std::function
 * actually will dynamically allocate memory if the size of input Functor (i.e. lambda or callable object)
 * has size exceeding the size of union _Nocopy_types (gcc, take a look at bits/std_function.h).
 * The following conditions applied to whether std::function will be allocated memory on the fly
 *
 *        static const bool __stored_locally =
      (__is_location_invariant<_Functor>::value
       && sizeof(_Functor) <= _M_max_size
       && __alignof__(_Functor) <= _M_max_align
       && (_M_max_align % __alignof__(_Functor) == 0));
 *
 * which you can also find it in the same header file as mentioned above.
 * A curiosity arises as to why _M_max_size (deduced to sizeof(_Nocpy_types)) has 16 as result but
 * quickly inspected in its union declaration consists only of pointer type.
 *
 * Yep, there is difference between pointer type and member function pointer type. The former is
 * 8 bytes, but the latter is 16 bytes (both in 64 bit system) as it need to hold "this" pointer
 * as part of the address of the member function to know which object to be called and operated on.
 *
 * More detail of reason can be read at http://lazarenko.me/wide-pointers/.
 */
#include <iostream>
#include <functional>       // included this just to have std::function and its _Nocopy_types available although we didn't use it

using namespace std;

struct TestSt
{
    char a[2];
    void bar() {};
};

union TestUn
{
    void *ptr;
    const void * ptr2;
    void (*func_ptr)();

    // this is a pointer to the member function of struct
    void (TestSt::*bar)();

    // member function doesn't has any effect of the sizeof(..struct/class..)
    void foo() {};
};

int main() {
    std::cout << "sizeof(const void*): " << sizeof(const void*) << '\n';
    std::cout << "sizeof(TestUn): " << sizeof(TestUn) << ", __alignof__: " << __alignof__(TestUn) << '\n';
    std::cout << "sizeof(TestUn::bar): " << sizeof(TestUn::bar) << '\n';

    std::cout << '\n';
    std::cout << "-- Checking size of _Nocopy_types --\n";
    std::cout << "sizeof(_Nocopy_types): " <<sizeof(_Nocopy_types) << '\n';
    std::cout << "__alignof__(_Nocopy_types): " << __alignof__(_Nocopy_types) << '\n';
    std::cout << "_M_function_pointer size: " << sizeof(_Nocopy_types::_M_function_pointer) << '\n';
    std::cout << "_M_member_pointer size: " << sizeof(_Nocopy_types::_M_member_pointer) << '\n';

    std::cout.flush();

    return 0;
}
