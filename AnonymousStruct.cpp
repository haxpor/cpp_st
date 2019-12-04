/**
 * Demonstrate the usage of anonymous struct in c++.
 * In c, anonymous struct (unnamed type and unnamed object) is not supported, but anonymous union. 
 * c++ thus also didn't support it to maintain compatibility with c but most compiler has support
 * of it although  c++11 stanard doesn't support.
 *
 * The benefit of anonymous struct is to be able to group the similar proximity or set of data together
 * without having to come up with a name for it (as naming variable is hard :)), also to limit the
 * scope of usage of it to be local within what wraps it which in our case here is outer union.
 *
 * Extra note:
 *  - same style of using anonymous struct inside union can be seen in CryEngine code in file
 *    CRYENGINE/Code/CryEngine/Cry3DEngine/terrain_sector.h for its SHeightMapItem union as well.
 *  - the point here is also that we can access member fields of wrapped struct directly from the
 *    variable name of outer union.
 */
#include <iostream>

union SharedSpace
{
    // make sure to check support with compiler
    // anonymous struct is not supported in standard, but compilers do support it anyway
    struct
    {
        int a;
        int b;
        int c;
        float d;
    };
    int main;
};

int main()
{
    SharedSpace ss;
    // the size now is the largest between anonymous struct, and union
    std::cout << "size of ShareSpace: " << sizeof(SharedSpace) << '\n';

    ss.main = 1;
    ss.a = 2;
    ss.b = 3;
    ss.c = 4;
    ss.d = 5.0f;

    std::cout << "main: " << ss.main << '\n';
    std::cout << "a: " << ss.a << '\n';
    // b, c, and d member fields can still be set, and compiler will reserve memory for it
    // but a certain comment on SO (https://stackoverflow.com/questions/13376494/what-are-the-benefits-of-unnamed-structs-unions-in-c#comment71910045_13377055)
    // mentions that the compiler might optimize it away by not reserving if we didn't really use
    // those memory area (accessing or setting b, c, or d).
    // Anyway result here with gcc, it did allocate memory area for it.
    std::cout << "b: " << ss.b << '\n';
    std::cout << "c: " << ss.c << '\n';
    std::cout << "d: " << ss.d << '\n';
    return 0;
}
