/**
 * Demonstrate that compiler will choose the last definition fo macro if it
 * defined in multiple locations even inside different namespace.
 *
 * So this means at the time of preprocessing, it didn't know anything yet about
 * namespace.
 * 
 */
#include <cassert>
#include <cstring>

#define FOO(x) "1st FOO(): " x
#define FOO(x) "2nd FOO(): " x

namespace A
{
	#define BAR "1st BAR"
}

namespace B
{
	#define BAR "2nd BAR"
}

int main()
{
	assert(std::strcmp(FOO("Hello world"), "2nd FOO(): Hello world") == 0);
	assert(std::strcmp(BAR, "2nd BAR") == 0);
	return 0;
}
