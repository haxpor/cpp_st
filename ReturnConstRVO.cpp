/**
 * Demonstrate prove-of-concept to RVO struct holding stack variable inside out from the function.
 *
 * Compile this program with
 * 'g++ -std=c++17 -Wall -Wextra ReturnConstRVO.cpp'
 *
 * to test out that it utilizes RVO so no copying of data, thus memory address of variable inside and outside
 * must be the same.
 *
 * ---
 *
 * (extra) Compile with
 * 'g++ -std=c++17 -Wall -Wextra -fno-elide-constructors -DNO_RVO ReturnConstRVO.cpp'
 *
 * to test without RVO, thus memory address will not be the same and copying happened behind the scene.
 */
#include <iostream>
#include <cstring>
#include <memory>
#include <cassert>
#include <cstdint>

inline constexpr int BUFFER_SIZE = 255;

static std::uintptr_t localAddress = 0;

struct Widget
{
	char buffer[BUFFER_SIZE];
};

Widget GetMeWidget(const char* txt)
{
	Widget localWidget;
	std::strcpy(localWidget.buffer, txt);
	localAddress = reinterpret_cast<std::uintptr_t>(std::addressof(localWidget));
	std::cout << "local address: " << localAddress << std::endl;
	return localWidget;
}

int main()
{
	const Widget w = GetMeWidget("Hello world");
	std::uintptr_t chkAddress = reinterpret_cast<std::uintptr_t>(std::addressof(w));
	std::cout << "address: " << chkAddress << std::endl;
	// no check for memory address equality if opt-in to use NO_RVO at compile time
#ifndef NO_RVO
	assert(localAddress == chkAddress && "Memory address must be equal for RVO case");
#endif
	assert(std::strcmp(w.buffer, "Hello world") == 0 && "Buffer content should equal to 'Hello world'");
	return 0;
}
