/**
 * Demonstrate immediate conversion from std::shared_ptr to std::weak_ptr right
 * after construction time.
 */
#include <memory>
#include <iostream>
#include <cassert>

struct Widget
{};

int main()
{
	{
		// normal case, use_count() still holds to 1
		std::shared_ptr<Widget> sptr = std::shared_ptr<Widget>(new Widget());
		assert(sptr.use_count() == 1);
	}
	{
		// construct a std::shared_ptr then immediately convert into std::weak_ptr
		// results in decrement of use_count right away
		std::weak_ptr<Widget> sptr = std::shared_ptr<Widget>(new Widget());
		assert(sptr.use_count() == 0);
	}
	
	return 0;
}
