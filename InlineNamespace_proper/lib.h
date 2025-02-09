namespace lib
{
	// Base implementation defined within the enclosure of namespace lib
#ifndef V2
	void foo();
#elif defined(V2)
	// only in case of newer implementation commenced. Just like to enable using __cxx11, then define _GLIBCXX_USE_CXX11_ABI definition at compile time.
	// Define V2 to use newer implementation of foo() in v2.
	inline namespace v2
	{
		void foo();
	}

	// further implementation like v3, v4, ... can be placed here onwards but V2 definition needs to still be defined (although silently behind users' awareness)
	// then the approach proceeds like what we did in InlineNamespace.cpp.
#endif
}
