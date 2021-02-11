#include "Consumer1.h"
#include "Consumer2.h"

int main()
{
	Consumer1 c1;
	Consumer2 c2;

	c1.Consumer1_PrintMemoryAddress();
	c2.Consumer2_PrintMemoryAddress();
	return 0;
}
