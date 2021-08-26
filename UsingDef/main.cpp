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
