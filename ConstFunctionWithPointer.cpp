/**
 * Demonstrate mutating object pointed to by a class's member field pointer whether it's possible or not.
 *
 * It depends on how we declare our pointer either const pointer, or pointer pointed to const data
 * then it will apply accordingly to const function.
 */

struct Data
{
    int foo;
};

class Widget
{
public:
    Widget(Data& d)
        : m(&d)
    {
    }

    // case 1
    void mutateData() const
    {
        m->foo = 2;
    }

    // case 2
    void mutatePointer() const
    {
        m = nullptr;
    }

private:
    Data* const m;
};

int main()
{
    Data d;
    Widget w(d);
    // case 1: uncomment, then you will see compiilation error as we try to modify data pointed to by a pointer
    //w.mutateData():
    // case 2: this is totally fine
    w.mutatePointer();
    return 0;
}
