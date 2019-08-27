#ifndef INLINE_H_
#define INLINE_H_

// marked as 'static' will prevent from external source file or program to be able to see it.
// Thus making dynamic linking not be able to see such symbol in linking.
// Result in undefined reference
static inline const int FixedNumber(const int n)
{
    return n + 10;
}

// This works normally
const int NormalFunc(int n);

#endif
