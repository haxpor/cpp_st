#include "source2.h"
#include "source1.h"

static int s_source2 = 20;

int Widget2::foo()
{
	Widget1 w1;
	return s_source2 + w1.foo();
}
