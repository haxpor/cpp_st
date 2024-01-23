/**
 * Implementation of atomic busy-wait approach
 * to synchronize each printing call to console.
 *
 * This should be fine if you know ahead that there would be
 * a very brief time waiting, so it won't busy spin too hard.
 *
 * This uses C++17 because of utilization of fold-expression
 * in C++17 in ts_print() function. It would need more effort
 * if implement in older version of C++ standard.
 *
 * Compile with
 * g++ -std=c++17 <source-file> -lpthread
 */
#include <thread>
#include <iostream>
#include <utility>
#include <atomic>

static std::atomic_flag gPrintLock = ATOMIC_FLAG_INIT;

template<typename... Args>
static void ts_print(Args&&... args)
{
	// spin-lock, that's fine for our usecase
	while (gPrintLock.test_and_set(std::memory_order_acquire))
		;
	
	((std::cout << std::forward<Args>(args)), ...) << std::endl;

	// release the lock
	gPrintLock.clear();
}

struct MyCallable
{
	int value;

	MyCallable(): value(0) {}
	MyCallable(int value_): value(value_) {}

	void operator()(const char* context) const
	{
		ts_print("[", context, "] ", value);
	}
};

int main()
{
	std::thread t1(MyCallable(), "t1");
	std::thread t2(MyCallable(), "t2");
	std::thread t3(MyCallable(10), "t3");
	std::thread t4(MyCallable(10), "t4");

	t1.join();
	t2.join();
	t3.join();
	t4.join();
	return 0;
}
