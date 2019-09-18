/**
 * Test to check value of std::basic_string::size after using its substr() function starting from
 * mid-range.
 *
 * Result the size is still 10, not 20 although the second parameter it will automatically supplies as 
 * string's size().
 */

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str("0123456789abcdefghij");
    string str2 = str.substr(10);
    cout << str2 << endl;
    cout << str2.size() << endl;
    return 0;
}
