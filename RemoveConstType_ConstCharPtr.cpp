/**
 * Test to validate that std::remove_const_t only removes the topmost const type only.
 * Thus 'const char*' after applied with std::remove_const_t, it's still the same type.
 */
#include <type_traits>

int main()
{
	// no topmost level of const
	static_assert(std::is_same_v<const char*, std::remove_const_t<const char*>>);
	// there is topmost level of const
	static_assert(std::is_same_v<const char*, std::remove_const_t<const char* const>>);
	return 0;
}
