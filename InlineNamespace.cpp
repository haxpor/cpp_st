/**
 * Lately I've dealt with linking issue in which the symbols as follows get generated
 *
 * - std::__cxx11 - for GCC
 * - std::__1 - for clang
 * 
 * These things revolve around the power of inline namespace that allow the newer implementation
 * of something to be a direct member of its parent namespace; this helps in not mentioning a specific
 * namespace name at all.
 *
 * Anyhow, if we have a future updated namespace, we would need to remove "inline" from previous
 * version implementation of inline namespace, in order to make the latest one a direct member
 * of the parent namespace. This is how compiler offer the usage of older implementation, and manage
 * the backward compatibility.
 */
#include <iostream>

namespace mylib
{
    // old version can be used via fully qualified name
    namespace v1
    {
        void foo()
        {
            std::cout << "v1 foo" << std::endl;
        }
    }

    // acts as if it's a direct member of its parent namespace
    // this should be the most recent version allowing public to use
    namespace v2
    {
        void foo()
        {
            std::cout << "v2 foo" << std::endl;            
        }
    }

	inline namespace v3
	{
		void foo()
		{
			std::cout << "v3 foo" << std::endl;
		}
	}
}

int main()
{
	// this would call the latest implementation
    mylib::foo();
	// same but via fully quaflified specification, this will call v2 impl
    mylib::v2::foo();
	// this would call the older implementation, this will call v1 impl
    mylib::v1::foo();

    return 0;
}
