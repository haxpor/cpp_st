#include "Inline.h"

const int NormalFunc(int n)
{
    n = FixedNumber(n); // now n = n + 10
    return n + 1;       // now n = n + 11
}
