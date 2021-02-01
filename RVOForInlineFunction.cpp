/**
 * If RVO kicks into play, then
 * both address of local struct and its data member variable 'buffer' must be equal
 * to variable received outside as it just moved out.
 */
#include <iostream>
#include <memory>
#include <cstring>
#include <cassert>
#include <cstdint>

static std::uintptr_t g_localAddress = 0;
static std::uintptr_t g_localBufferAddress = 0;

// this one might not be necessary to include here
// but to shorten the code all elsse we have to do
template <typename T>
constexpr std::uintptr_t AddressInNumeric(const T& t)
{
	return reinterpret_cast<std::uintptr_t>(std::addressof(t));
}

struct Widget
{
	char buffer[256];
};

inline Widget Foo(const char* txt)
{
	Widget newObj;
	std::strcpy(newObj.buffer, txt);
	// save the address of the local variable
	// we will validate it outside
	g_localAddress = AddressInNumeric(newObj);
	g_localBufferAddress = AddressInNumeric(newObj.buffer);

	std::cout << "local address: " << std::addressof(newObj) << '\n';
	std::cout << "local buffer address: " << std::addressof(newObj.buffer) << std::endl;
	return newObj;
}

int main()
{
	Widget myWidget = Foo("Hello world");
	// validate if buffer is content of buffer is still the same
	assert(std::strcmp(myWidget.buffer, "Hello world") == 0);

	std::cout << "received address: " << std::addressof(myWidget) << std::endl;
	std::cout << "received buffer address: " << std::addressof(myWidget.buffer) << std::endl;

	// validate if the RVO kicks into play
	assert(AddressInNumeric(myWidget) == g_localAddress);
	// validate its buffer address if the RVO kicks into play
	assert(AddressInNumeric(myWidget.buffer) == g_localBufferAddress);
	return 0;
}
