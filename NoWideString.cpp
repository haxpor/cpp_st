/**
 * We can represent unicode string **without** using wide-string e.g. UTF-16, UTF-32 encoding scheme
 * and print it properly on Windows. But we have to instruct it to use UTF-8.
 *
 * Either compile with
 * $ cl.exe /EHsc /O2 /W3 /std:c++17 /utf-8 NoWideString.cpp
 * which is equivalent to
 * $ cl.exe /EHsc /O2 /W3 /std:c++17 /source-charset:utf-8 /execution-charset:utf-8 NoWideString.cpp
 *
 * See https://learn.microsoft.com/en-us/cpp/build/reference/execution-charset-set-execution-character-set?view=msvc-170
 *
 * $ g++ -std=c++17 -O2 -Wall NoWideString.cpp (tested with 9.5)
 *
 */
#include <iostream>
#include <string>

// I opt to check for platform here instead of compiler
// but it would be nice to test compiling with gcc on Windows to see the difference
#if _WIN32
#include <clocale>              // we can comment this line, not neccessary
#include <Windows.h>
#endif

int main()
{
#if _WIN32
    // use UTF-8 character encoding
        std::setlocale(LC_ALL, ".UTF-8");       // we can comment this line, not necessary
        SetConsoleOutputCP(CP_UTF8);
#endif
    std::string str = u8"Лорем ипсум долор сит амет, консектетур адиписцинг элит";
    std::cout << str << std::endl;
    return 0;
}
