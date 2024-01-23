/**
 * Overriding std::malloc() in c++.
 * 
 * Notice
 * - we cannot print anything onto console within malloc() function at all,
 *   otherwise it will segfault. Validate the code execution via debugger.
 * - RTLD_NEXT used to find the next symbol, not the first found
 * - findAndCacheRealMalloc() needs to be called nested inside overridden malloc() in order to make compiler see malloc symbol fist, to make RTLD_NEXT works
 *
 * Compile with
 * g++ -std=c++17 -g <soruce-file> -ldl
 */
#include <iostream>
#include <cstdlib>
#include <cassert>
#include <functional>
#include <dlfcn.h>
#include <cstring>

static std::function<void*(size_t)> sRealMalloc;

static void findAndCacheRealMalloc()
{
	// RTLD_NEXT is used to find the next symbol
	// from the one that is already found which is our custom defined malloc
	//
	// NOTE: the code needs to make a call to malloc() prior to this
	// in order for symbol to be discovered.
	//
	// Tested independently calling findAndCacheRealMalloc() separately
	// without nesting its function call inside malloc(), it won't be able 
	// to find the correct symbol of malloc.
	void* funcPtr = dlsym(RTLD_NEXT, "malloc");
	sRealMalloc = reinterpret_cast<void*(*)(size_t)>(funcPtr);
}

extern "C" void* malloc(size_t size)
{
	if (sRealMalloc == nullptr)
		findAndCacheRealMalloc();

	return sRealMalloc(size);
}

int main()
{
	assert(!sRealMalloc);	// validate initial state

	void* ptr = malloc(10);
	assert(ptr != nullptr);
	assert(sRealMalloc);	// validate post-state of by-now set to real malloc function

	// validate copying data into the allocated heap memory with our custom malloc
	const char* srcStr = "hello";
	std::strncpy(static_cast<char*>(ptr), srcStr, 6);

	std::cout << reinterpret_cast<const char*>(ptr) << std::endl;
	assert(std::string(srcStr) == std::string(reinterpret_cast<const char*>(ptr)));

	std::free(ptr);
	
	return 0;
}
