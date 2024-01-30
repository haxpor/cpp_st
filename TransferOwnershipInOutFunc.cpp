/**
 * Inspired by the book C++ Concurrency in Action
 *
 * This nitffy detail is of object moving mentioned by a particular section within first 2 chapters
 * of the book, if readers didn't read it too fast, or skim through the text too quick.
 *
 * Yeah the book several C++ details that solidify the understanding of the stuff.
 *
 * This test case is about transfering the ownership of the std::thread but at the same time,
 * demonstrates the automatic move semantics applied on the temporary object, otherwise we would
 * have to explicitly move ourselves.
 *
 * Compile:
 * g++ -std=c++17 <source-file> -lpthread
 */
#include <thread>
#include <iostream>

void foo()
{
	std::cout << "something" << std::endl;
}

void f(std::thread t)
{
	t.join();
}

int main()
{
	f(std::thread(foo));	// temp object moves automatically

	std::thread t2(foo);
	f(std::move(t2));	// named value, we need to explicitly move
	return 0;
}
