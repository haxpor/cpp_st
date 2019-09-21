/**
 * Demonstrate usage and power of <type_traits> in C++
 * This include ability of type checking at compile time for following
 *  - std::is_integral
 *  - std::is_floating_point
 *  - std::is_class
 *  - std::is_pointer
 *  - std::is_function
 *  - std::is_rvalue_reference
 *  - std::is_standard_layout
 *  - others
 */
#include <iostream>
#include <type_traits>
#include <iomanip>

#define PF PrintFormat()

using namespace std;

struct DummyA
{
public:
    int DummyFunction() const { return 1; }
private:
    int n;
};

class DummyB
{
public:
    int DummyFunction() const { return 1; }
private:
    int n;
};

struct DummyC
{
public:
    int DummyFunction() const { return 1; }
private:
    int n;
};

class DummyD
{
public:
   virtual int DummyFunction() const { return 1; }
private:
  int n; 
};

class DummyE: public DummyD
{
public:
    virtual int DummyFunction() const override { return 2; }

    // note: ref-qualifier is possible in C++11
    // there are 3 cases
    // 1.) const& - this member function can be used only with const, non-const, and lvalue-reference object
    // 2.) &      - this member function can be used only with non-const object
    // 3.) &&     - this member function can be used only with rvalue-reference object
    // Read more https://stackoverflow.com/questions/28066777/const-and-specifiers-for-member-functions-in-c,
    //  and https://en.cppreference.com/w/cpp/language/member_functions
    virtual int DummyFunction2() const& { return 3; }
};

static ostream& PrintFormat()
{
    cout << boolalpha << left << setw(60);
    return cout;
}

static void f();

// used to get type of input T::*
template <typename>
struct ClassFunc {};

template <class T, class R>
struct ClassFunc<R T::*>
{
    // these two lines have the same effect, in reality just use one over another
    // note: `using` is supported for C++11
    typedef R func_member_type;
    using member_type = R;
};

int main()
{
    int n1 = 10;
    long n2 = 100;
    float n3 = 200;
    double n4 = 300;
    float* ptr = &n3;
    auto funct = [](int n) { cout << "Called within lambda function: " << n << endl; };

    // these two lines give the same result
    // interesting definition is as follows (as seen in <type_traits>
    //
    //      constexpr operator value_type() const noexcept { return value; }
    //      constexpr value_type operator()() const noexcept { return value; }
    //
    //  it's chained together and thus makes is_integral<int>() possible to return value
    //  and it's still compile time. Only for C++11 and up.
    PF << "int is integral type (via operator()): " << is_integral<int>() << endl;
    PF << "int is integral type (via ::value): " << is_integral<int>::value << endl;

    // in C++11, there is no more typeof() which available for <C++11
    //cout << boolalpha << is_floating_point<typeof(n3)>::value << endl;
    PF << "decltype(n3) is floating point type: " << is_floating_point<decltype(n3)>::value << endl;

    PF << "delctype(n4) is floating point type: " << is_floating_point<decltype(n4)>::value << endl;
    PF << "double is floating point type: " << is_floating_point<double>::value << endl;
    PF << "long is not floating point type: " << is_floating_point<long>::value << endl;

    PF << "float* is pointer type: " << is_pointer<float*>::value << endl;
    PF << "ptr is pointer type: " << is_pointer<decltype(ptr)>::value << endl;

    // lambda isn't counted as function
    PF << "funct is function type: " << is_function<decltype(funct)>::value << endl;
    PF << "f() is function type: " << is_function<decltype(f)>::value << endl;
    using T1 = ClassFunc<decltype(&DummyE::DummyFunction2)>::member_type;       // T = int() const override
    using T2 = ClassFunc<decltype(&DummyE::DummyFunction2)>::func_member_type;  // same, but now we actually typedef-ed it
    PF << "DummyE::DummyFunction2 is function type (via using): " << is_function<T1>::value << endl;
    PF << "DummyE::DummyFunction2 is function type (via typedef): " << is_function<T2>::value << endl;

    PF << "DummyA is class type: " << is_class<DummyA>::value << endl;
    PF << "DummyB is class type: " << is_class<DummyB>::value << endl;
    PF << "DummyC is class type: " << is_class<DummyC>::value << endl;

    PF << "DummyC is standard layout: " << is_standard_layout<DummyC>::value << endl;
    PF << "DummyD is standard layout: " << is_standard_layout<DummyD>::value << endl;
    PF << "DummyE is standard layout: " << is_standard_layout<DummyE>::value << endl;

    PF << "int is rvalue-reference type: " << is_rvalue_reference<int>::value << endl;          // this is prvalue
    PF << "int& is rvalue-reference type: " << is_rvalue_reference<int&>::value << endl;        // this is lvalue-reference
    PF << "int&& is rvalue-reference type: " << is_rvalue_reference<int&&>::value << endl;      // this is xvalue (and rvalue-reference)

    return 0;
}
