/**
 * Validate full-fledge constructor and assignment operator.
 * Interesting read: https://stackoverflow.com/a/3279550/571227
 *
 * Compile with and without -fno-elide-constructors with gcc to see different results to compare.
 *
 * With RVO copy move constructor will not be necessary as it creates a copy of object at the returning
 * of the function, or from somewhere on rhs about to return and assign to lhs, it uses only a single
 * copy then assign to the receiving variable at the call site. So don't be confused that RVO
 * will need move constructor or move assignment operator to be implemented for both. It's feature
 * provided by compiler. Move constructor/assignment operator will kick in and be used whenever
 * RVO isn't possible (https://stackoverflow.com/questions/5031778/what-optimization-does-move-semantics-provide-if-we-already-have-rvo#comment5628760_5031859).
 * 
 *
 * Move semantics should not be thought as an optimization device - https://stackoverflow.com/a/5031878/571227
 *
 *
 * If you implemented both non-const assignment operator, and move assignment operator then it will
 * be ambiguous, see below.
 *
 *          CC.cpp: In function ‘int main()’:
 *       CC.cpp:88:16: error: ambiguous overload for ‘operator=’ (operand types are ‘Widget’ and ‘Widget’)
 *          88 |     a = Widget();   // here
 *             |                ^
 *       CC.cpp:38:13: note: candidate: ‘Widget& Widget::operator=(Widget)’
 *          38 |     Widget& operator=(Widget other)
 *             |             ^~~~~~~~
 *       CC.cpp:46:13: note: candidate: ‘Widget& Widget::operator=(Widget&&)’
 *          46 |     Widget& operator=(Widget&& other)
 *
 *
 *  Interesting read about RVO vs std::move: https://www.ibm.com/developerworks/community/blogs/5894415f-be62-4bc0-81c5-3956e82276f3/entry/RVO_V_S_std_move?lang=en
 */

#include <iostream>
#include <algorithm>

struct Widget
{
    Widget()
    {
        std::cout << "ctor" << std::endl;
    }
    Widget(const Widget& other)
    {
        std::cout << "ctor - const ref" << std::endl;
    }
    Widget(Widget&& other)
    {
        std::cout << "ctor - move" << std::endl;

        using std::swap;
        swap(*this, other);
    }
    //Widget& operator=(Widget other)
    //{
    //    std::cout << "assignment operator" << std::endl;

    //    using std::swap;
    //    swap(*this, other);
    //    return *this;
    //}
    Widget& operator=(const Widget& other)
    {
        std::cout << "(const) assignment operator" << std::endl;

        return *this;
    }
    Widget& operator=(Widget&& other)
    {
        std::cout << "assignment move operator" << std::endl;

        using std::swap;
        swap(*this, other);
        return *this;
    }
    ~Widget()
    {
        std::cout << "dtor" << std::endl;
    }

    friend inline void swap(Widget& first, Widget& second)
    {
        std::cout << "swap" << std::endl;
    }
};

Widget foo()
{
    return Widget();
}

Widget&& foo2()
{
    return Widget();
}

Widget&& foo3()
{
    return std::move(Widget());
}

int main()
{
    // the following 1: and 2: are cases which can happen
    // in case of 1: RVO, and 2: non-RVO

    // 1: not apply
    // 2: ctor, dtor
    {
    std::cout << "1" << std::endl;
    Widget a;
    }

    // 1: ctor, dtor
    // 2: ctor, move ctor, swap, dtor, dtor
    {
    std::cout << "2" << std::endl;
    Widget a = Widget();
    }
    
    // wrong intention, not construct object
    // but declare function named 'a' returning Widget
    {
    std::cout << "3" << std::endl;
    Widget a();
    }    

    // same as 1
    // another form of initialization called 'list initialization'
    {
    std::cout << "4" << std::endl;
    Widget a { };
    }
    
    // 1: ctor, ctor, dtor, dtor
    // 2: ctor, ctor, move assignment, swap, dtor, dtor
    {
    std::cout << "5" << std::endl;
    Widget a;
    a = Widget();   // here
    }

    // 1: ctor, dtor
    // 2: ctor, move ctor, swap, dtor, move ctor, swap, dtor, dtor
    {
    std::cout << "6" << std::endl;
    Widget c = foo();
    }

    // 1: ctor, dtor, ctor - move, swap, dtor
    // 2: ctor, dtor, ctor - move, swap, dtor
    {
    std::cout << "7" << std::endl;
    Widget c = foo2();
    }

    // 1: ctor, dtor, ctor - move, swap, dtor
    // 2: ctor, dtor, ctor - move, swap, dtor
    {
    std::cout << "8" << std::endl;
    Widget c = foo3();
    }

    return 0;
}
