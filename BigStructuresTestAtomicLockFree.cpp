/** Demonstrate whether big structures would have lock-free operation with std::atomic or not.
 */

#include <atomic>
#include <iostream>
#include <cassert>

struct Small
{
	int a;
};

struct SmallStillOk
{
	int a;
	int b;
};

struct Big
{
	int a;
	int b;
	float c;
};

int main()
{
	std::atomic<Small> mySmallSt;
	std::atomic<SmallStillOk> mySmallStillOkSt;
	std::atomic<Big> myBigSt;

	assert(mySmallSt.is_lock_free() && "Small structure should be lock-free for std::atomic");
	assert(mySmallStillOkSt.is_lock_free() && "SmallStillOk structure should be lock-free for std::atomic");

	// compiler will shout out error at compile time because std::atomic<Big>::is_lock_free() is undefined.
	// This is due to if compiler cannot provide lock-free mechanism (as its size is too big) toward the type i.e. in this case Big type, then
	// it will resolve to use external function call with the same name. See https://gcc.gnu.org/onlinedocs/gcc-7.1.0/gcc/_005f_005fatomic-Builtins.html#g_t_005f_005fatomic-Builtins
	//assert(myBigSt.is_lock_free() && "Big structure should not be lock-free for std::atomic");
	return 0;
}
