/**
 * Inspired by the book C++ Concurrency in Action.
 *
 * Thread id can be used to differentiate and identify which thread is which.
 * It is one of supported types by std::hash thus can be used as a key of
 * associatitve unordered container (hashmap).
 *
 * It also has support for complete set of comparison operators ==, !=, <, <=, >, and >=
 * in which only friend function declared as of ==, and < to cover all comparison operators.
 *
 * At least on GCC, underlying type of std::thread::id is unsigned long.
 *
 * Compile:
 * g++ -std=c++17 <source-file> -lpthread
 */
#include <thread>
#include <iostream>

// thread id of the main thread
static std::thread::id sMainThreadId = std::this_thread::get_id();

void f()
{
	if (std::this_thread::get_id() == sMainThreadId)
	{
		std::cout << "main thread executes" << std::endl;
	}
	else
	{
		std::cout << "spawned thread executes" << std::endl;
	}
}

int main()
{
	std::cout << sMainThreadId << std::endl;

	std::thread t1(f);	// spawned thread executes
	t1.join();

	f();	// main thread executes
	return 0;
}
