#include "Consumer.h"

int main()
{
    Consumer c;
    c.SetNum(150);

    // Cannot do this, Widget is not a member of Consumer
    // it is just a forward declared
    //Consumer::Widget w2;

    Widget w;
    w.Print(c);
    return 0;
}
