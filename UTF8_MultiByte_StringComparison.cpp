/**
 * I understand there is a place and time in consideration of using whichever of either
 * 1. wide-string
 * 2. UTF8 (Multi-byte) string
 *
 * to represent unicode string in the code base. There is pros/cons.
 *
 * This example demonstrates that string comparison for UTF8 string can be dont naturally,
 * and its multibyte involved code-point and stuff would be handled behind the scene without
 * us to worry about it.
 *
 * Anyhow as far as I can think of, there is one place that would benefit from directly
 * using a wide-character/string data type which is when we want to inspect each unicode
 * character value directly without involving of conversion from narrow to wide, etc.
 */
#include <iostream>
#include <string>
#include <cstdint>
#include <cassert>

int main() {
    std::wstring myWString = L"你好，世界！Hello, World!";
    std::string utf8String = u8"你好，世界！Hello, World!";

    //std::wcout << myWString << std::endl;   // bonker!, uncomment this line might interfere with output from the next line
    std::cout << utf8String << std::endl;   // totally fine

    // comparison
    assert(myWString.find(L"你好，世界！") != std::wstring::npos);
    assert(utf8String.find(u8"你好，世界！") != std::string::npos);

    return 0;
}
