/**
 * Test compiler's warning on the simple format string associating with std::size_t.
 * std::size_t type on the following platform as investigated via header file (used compiler to expand)
 * - Windows: unsigned int
 * - Linux: long unsigned int
 *
 * Warning output depends on which compiler we use, and warning level flags
 * - MSVC: /Wall will give out warning about not using %zu
 * - Linux: always spit out warning
 */
#include <cstdio>

int main()
{
	std::size_t st = 1;
	std::printf("%u", st);
	return 0;
}
