/**
 * Continued test case but loading a shard library in runtime.
 * See StaticVarDtorInSharedLibrary first.
 *
 * (Bonus) this also use dlsym from dl library to check if global symbol in
 * such shared library is loaded to validate that such shared library is actually
 * loaded.
 */
#include <iostream>
#include <dlfcn.h>
#include <cassert>
#include <cstring>

int main()
{
	// load .so in runtime
	void* dlHandle = dlopen("./libdummy.so", RTLD_NOW | RTLD_DEEPBIND);
	void(*dl_foo)() = (void(*)())(dlsym(dlHandle, "foo"));
	assert(dl_foo != nullptr);
	dl_foo();
	if (dlclose(dlHandle) != 0)
	{
		std::fprintf(stderr, "Error dclose(): %s\n", dlerror());
		return -1;
	}

	std::cout << "prior to end of main()\n";
	return 0;
}
