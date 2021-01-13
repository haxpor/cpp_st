/**
 * Demonstrate effect of `static constexpr` which will inline declaration for us.
 * Validate via generated assembly output.
 */
#include "MyLib.h"

int main()
{
	MyLib::PrintValueAddress();
	return 0;
}
