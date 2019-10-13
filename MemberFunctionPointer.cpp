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
#include <cstring>

using namespace std;

struct TestBare
{
    // nothing here
};

struct TestSt
{
    char a[2];
    void bar() {};
    virtual void foo() {};
};

struct TestStDerived: public TestSt
{
    virtual void foo() override { };
};

union TestUn
{
    void *ptr;
    const void * ptr2;
    void (*func_ptr)();

    // this is a pointer to the member function of struct
    void (TestSt::*bar)();

    void (TestSt::*foo)();

    // member function doesn't has any effect of the sizeof(..struct/class..)
    void foo_func() {};
};

static void inspectVirtualMemberFunction_TestSt(const TestSt* obj, void (TestSt::*any_mem_func)())
{
    void *data[2];
    std::memcpy(data, &any_mem_func, sizeof(any_mem_func));
    std::cout << "  vtable base pointer of TestSt: " << std::addressof(((long*)obj)[0]) << '\n';
    std::cout << "  Function pointer (diff): " << data[0] << '\n';
    std::cout << "  Pointer adj: " << data[1] << '\n';
}

static void inspectVirtualMemberFunction_TestStDerived(const TestStDerived* obj, void (TestStDerived::*any_mem_func)())
{
    void *data[2];
    std::memcpy(data, &any_mem_func, sizeof(any_mem_func));
    std::cout << "  vtable base pointer of TestStDerived: " << std::addressof(((long*)obj)[0]) << '\n';
    std::cout << "  Function pointer (diff): " << data[0] << '\n';
    std::cout << "  Pointer adj: " << data[1] << '\n';
}

int main() {
    TestUn u;
    TestSt s;
    TestStDerived s_derived;

    std::cout << "sizeof(const void*): " << sizeof(const void*) << '\n';
    std::cout << "sizeof(TestUn): " << sizeof(TestUn) << ", __alignof__: " << __alignof__(TestUn) << '\n';
    std::cout << "sizeof(TestUn::bar): " << sizeof(TestUn::bar) << '\n';
    std::cout << "sizeof(TestUn::foo): " << sizeof(TestUn::foo) << '\n';
    std::cout << "TestSt::bar\n";
    inspectVirtualMemberFunction_TestSt(&s, &TestSt::bar);
    std::cout << "TestSt::foo (virtual function)\n";
    inspectVirtualMemberFunction_TestSt(&s, &TestSt::foo);
    std::cout << "  sizeof(TestSt): " << sizeof(TestSt) << '\n';

    std::cout << "TestStDerived::foo (virtual function)\n";
    inspectMVirtualMemberFunction_TestStDerived(&s_derived, &TestStDerived::foo);
    std::cout << "  sizeof(TestStDerived): " << sizeof(TestStDerived) << '\n';

    std::cout << "sizeof(TestBare): " << sizeof(TestBare) << '\n';      // class with no member data and virtual member function will have at least 1 byte
                                                                        // as it cannot has 0 byte in size

    std::cout << '\n';
    std::cout << "-- Checking size of _Nocopy_types --\n";
    std::cout << "sizeof(_Nocopy_types): " <<sizeof(_Nocopy_types) << '\n';
    std::cout << "__alignof__(_Nocopy_types): " << __alignof__(_Nocopy_types) << '\n';
    std::cout << "_M_function_pointer size: " << sizeof(_Nocopy_types::_M_function_pointer) << '\n';
    std::cout << "_M_member_pointer size: " << sizeof(_Nocopy_types::_M_member_pointer) << '\n';

    std::cout.flush();

    return 0;
}
