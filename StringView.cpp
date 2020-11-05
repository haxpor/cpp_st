/**
 * Demonstrate usage of std::string_view
 * Compile with -std=c++17
 *
 * std::string_view defers the real copying and more expensive operation into the time that it
 * needs it e.g. when to print out, call on its string-related member functions, etc.
 *
 * Note that std::string_view doesn't have null-terminated, it's not a buffer, it's just a view into
 * the real string buffer. Thus it doesn't store null-terminated character.
 */
#include <string>
#include <string_view>
#include <iostream>
#include <cassert>

void printSubString(std::string_view sv, int start, int length)
{
    assert(start + length <= sv.length() && "Length of string is not long enough");
    std::cout << sv.substr(start, length) << std::endl;
}

int main()
{
    std::string myString = "Hello world";
    std::string_view myStringView = myString;

    std::cout << myString << '\n';
    std::cout << myStringView << '\n';

    std::cout << myStringView.substr(0,5) << '\n';
    printSubString(std::string_view(myString), 0, 2);
    return 0;
}
