/**
 * To prove that we can access base class's 'using' without a need
 * to fully qualify the name.
 *
 * std::__allocator_traits_base in which std::allocator_traits derives from
 * makes use of this approach.
 *
 * (optional) Constrast this with data member, or function member in which we need to fully
 * qualify the class name.
 */

struct Base
{
	using pointer_t = void*;
};

struct Derived : public Base
{
	void Foo() const
	{
		int val = 0;
		(pointer_t)&val;			// can access without a need to specify class name like Base::pointer_t
		(Base::pointer_t)&val;		// also work
	}
};

int main()
{
	[[maybe_unused]] Derived d;
	return 0;
}
