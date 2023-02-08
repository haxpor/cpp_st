/**
 * Validate that "using" needs definition to be existing at the time of
 * declaration as well. But we can forward declare it.
 *
 * This would help in separate header file out and in architecturing our
 * classes/files structure.
 */
#include "Hdr.h"
#include "MyAnotherType.h"
#include <iostream>
#include <cassert>

int main()
{
	MyFuncSigT func = [](MyAliasedType& t) {
		std::cout << t.m_val << "\n";
		assert(t.m_val == 10);
	};

	MyAliasedType s;
	s.m_val = 10;

	func(s);
	return 0;
}
