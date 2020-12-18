/**
 * Thing is 
 * "We cannot use `using namespace` inside class scope, but can in function scope."
 */
#include "lib.h"

int main()
{
	Widget w;
	w.begin();

	// not possible because `using namespace cannot be used inside class scope, so it's not trasfered here.
	//Util::trycall();
	return 0;
}
