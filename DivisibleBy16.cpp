/**
 * Program to see if given number is divisible by 16 without using % or /.
 */

#include <iostream>
#include <cmath>

using namespace std;

static bool IsDivisibleBy16Method1(int num)
{
    int anum = std::abs(num);
    while (anum >= 16)
        anum -= 16;

    return anum == 0;
}

static bool IsDivisibleBy16Method2(int num)
{
    int anum = std::abs(num);
    int d = anum >> 4;
    while (d > 0)
    {
        anum -= (d << 4);
        d = anum >> 4;
    }

    return anum == 0;
}

int main()
{
    cout << boolalpha << IsDivisibleBy16Method1(0) << endl;
    cout << boolalpha << IsDivisibleBy16Method1(6) << endl;
    cout << boolalpha << IsDivisibleBy16Method1(16) << endl;
    cout << boolalpha << IsDivisibleBy16Method1(-16) << endl;
    cout << boolalpha << IsDivisibleBy16Method1(67) << endl;

    cout << endl;

    cout << boolalpha << IsDivisibleBy16Method2(0) << endl;
    cout << boolalpha << IsDivisibleBy16Method2(6) << endl;
    cout << boolalpha << IsDivisibleBy16Method2(16) << endl;
    cout << boolalpha << IsDivisibleBy16Method2(-16) << endl;
    cout << boolalpha << IsDivisibleBy16Method2(67) << endl;

    return 0;
}
