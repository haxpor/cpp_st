/**
 * Demonstrate the use of placement new operator to construct std::mutex
 * in which it is neither copyable nor movable.
 */

#include <mutex>
#include <cassert>

int main()
{
	std::mutex* mAllocAreaPtr = new std::mutex();

	// placement new operator (per se in-place construct)
	new (mAllocAreaPtr) std::mutex;

	// try to lock (which should be successful)
	// CAVEAT: taken into account of spurious return false even no thread owns such mutex)
	assert(mAllocAreaPtr->try_lock());
	mAllocAreaPtr->unlock();

	// we need to manually call destructor
	mAllocAreaPtr->~mutex();

	// repeat constructing std::mutex again
	new (mAllocAreaPtr) std::mutex;

	// do it again the same
	assert(mAllocAreaPtr->try_lock());
	mAllocAreaPtr->unlock();

	mAllocAreaPtr->~mutex();

	delete mAllocAreaPtr;
	return 0;
}
