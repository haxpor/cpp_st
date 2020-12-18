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
	// As well as ...
	// `using ...` can only be used with member data not arbitrary name (see comment inside lib.h file)
	//Util::trycall();
	return 0;
}
