#include <iostream>

struct Data
{
    int n;
    Data(): n(0) { std::cout << "ctor" << std::endl; }
    Data(int n): n(n) { std::cout << "ctor" << std::endl; }
    ~Data() { std::cout << "dtor" << std::endl; }
};

// we won't see this as argument to AttemptModifyPointerArgument() is a pointer (not pointer
// to pointer) thus it cannot modify where to point to for such pointer. Actually it passed
// by value. ptr outside and inside the function are different.
static void AttemptModifyPointerArgument(const Data* ptr)
{
    ptr = nullptr;

    // TODO: uncomment this line to see effect of compile error for attempt to modify constant value
    //ptr->n = 2;
}

// added 'const' is redundant here as pointer is passed by value
// we still cannot modify where of such pointer to point affecting the original pointer outside
// even without const
// But attempt to do so will generate compile error inside the function.
static void AttemptModifyPointerArgument2(const Data* const ptr)
{
    // TODO: uncomment this line to see the effect of compile error for attempt to modify constant pointer
    //ptr = nullptr;
}

// now technically we cannot modify where to point to for ptr
// but now we can modify value pointed to by such pointer.
static void AttemptModifyPointerArgument3(Data* const ptr)
{
    ptr->n = 10;
}

// redundant case, this has the same effect as case 3 just less pragmatic about const-ness for pointer argument
static void AttemptModifyPointerArgument4(Data* ptr)
{
    ptr->n = 11;
    ptr = nullptr;  // has no effect for outside of this function
}

// for c++, we take benefit of reference type (&) which can be applied to pointer as well
// so this might reduce the mental effort in using pointer to pointer
static void AttemptModifyPointerArgument5(Data*& ptr)
{
    ptr->n = 12;
    ptr = nullptr;
}

// same as case 5, but use bare metal pointer to pointer (double pointer) instead
// this requires both end from call site, and inside function to handle things properly
// call site: use &ptr to supply as argument
// function: deference with * to get the actual pointer to operate further on
static void AttemptModifyPointerArgument6(Data** ptr)
{
    // Note: -> has precedence over * thus we need parenthesis
    (*ptr)->n = 13;
    (*ptr) = nullptr;
}

// we cannot modity ptr
static void AttemptModifyPointerArgument7(Data** const ptr)
{
    // TODO: uncomment this line to see effect of compile error from attempt to modify constant pointer
    //ptr = nullptr;
}

// build on top of case 7, now ptr cannot be modified as well as its pointed to value; actual pointer which points
// to the data
static void AttemptModifyPointerArgument8(Data* const * const ptr)
{
    // TODO: uncomment to see the effect of compile error from attempt to modify constant pointer
    //(*ptr) = nullptr;
    
    // anyway, we can still modify value pointer points to
    (*ptr)->n = 100;
}

// build on top of case 8: now we cannot modify value which pointed to by pointer
static void AttemptModifyPointerArgument9(const Data* const * const ptr)
{
    // TODO: uncomment this line to see the effect of compile error from attempt to modify constant value
    //(*ptr)->n = 200;
}

// build on top of case 7 and 8: if the intention is clear that we can modify ptr (from where it should be pointing to)
// then use reference type of argument (&) is clearer and less mental effort in working in multi-level of pointer.
// see https://stackoverflow.com/a/14754987 for more information.
// I guess that because using reference, you expect to change its value, but now as data is constant,
// this doesn't make sense anymore thus compile error. 
static void AttemptModifyPointerArgument10(const Data*& ptr)
{
    ptr = nullptr;
}

int main()
{
    Data* ptr = new Data(1);
    Data* ptr2 = ptr;
    Data* ptr3 = ptr2;
    AttemptModifyPointerArgument(ptr);
    if (ptr == nullptr)
        std::cout << "ptr is now null" << std::endl;

    AttemptModifyPointerArgument2(ptr);

    AttemptModifyPointerArgument3(ptr);
    // value should be 10 now
    std::cout << ptr->n << std::endl;

    AttemptModifyPointerArgument4(ptr);
    // value should be 11 now
    std::cout << ptr->n << std::endl;
    if (ptr == nullptr)
        // should not print, it has no effect from the function call earlier
        std::cout << "ptr is now null" << std::endl;

    AttemptModifyPointerArgument5(ptr);
    // value should be 12 now
    // Note: we use ptr2 which still points to original data to get its value to print
    std::cout << ptr2->n << std::endl;
    if (ptr == nullptr)
        std::cout << "ptr is now null" << std::endl;

    // as ptr was set to nullptr, we supply the argument with ptr2
    AttemptModifyPointerArgument6(&ptr2);
    // value should be 13 now
    // Note: we use ptr3 which still points to original data to get its value to print
    std::cout << ptr3->n << std::endl;
    if (ptr2 == nullptr)
        std::cout << "ptr2 is now null" << std::endl;

    AttemptModifyPointerArgument7(&ptr3);
    AttemptModifyPointerArgument8(&ptr3);
    // value should be 100 now
    std::cout << ptr3->n << std::endl;

    AttemptModifyPointerArgument9(&ptr3);

    // the following 3 lines (actually first line) if uncommented won't compile
    // read more about this issue at AttemptModifyPointerArgument10() comment
    //AttemptModifyPointerArgument10(ptr3);
    //if (ptr3 == nullptr)
    //    std::cout << "ptr3 is now null" << std::endl;
    
    // as ptr was set to nullptr, and we only have ptr3 which points to original data
    // thus use ptr3 to delete the original data
    if (ptr3) delete ptr3;
    return 0;
}
