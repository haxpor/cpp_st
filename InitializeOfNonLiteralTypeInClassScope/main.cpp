/**
 * Prove of concept that initialization of non-literal type inside class scope
 * is not possible.
 *
 * You will see compilation error along the line of
 *
 * error: in-class initialization of static data member 'Widget ....' of non-literal type
 *
 * PS: either it is static or not, is not our concerned for this, thing is we cannot initialize it inside class scope.
 */
#include "Consumer.h"
#include <cassert>
#include <memory>

int main()
{
	assert(global_w.val == 1 && "val initialized should equal to 1");

	return 0;
}
