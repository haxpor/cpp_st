/**
 * Demonstrate that we can initialize non-static data member of namespace, and class scope
 * without problem. This is possible since c++11 (ref https://web.archive.org/web/20160316174223/https://blogs.oracle.com/pcarlini/entry/c_11_tidbits_non_static).
 */
#include <cassert>

struct StructVar
{
	StructVar(int val):
		m_val(val)
	{
	}

	int m_val;
};

namespace A
{
	namespace B
	{
		StructVar myStructVar = StructVar(2);
	}
}

class Widget
{
public:
	StructVar myStructVar = StructVar(3);
};

int main()
{
	assert(A::B::myStructVar.m_val == 2);
	Widget w;
	assert(w.myStructVar.m_val == 3);

	return 0;
}
