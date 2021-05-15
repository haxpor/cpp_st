/**
 * Proof of concept for pointer to member working with function template.
 */
#include <cassert>
#include <iostream>

struct Widget
{
	void Foo() const
	{
		std::cout << "Foo()" << std::endl;
	}

	void Bar() const
	{
		std::cout << "Bar()" << std::endl;
	}

	int m_val;
};

// pluggable function to be called on behalf of `w`
template <typename T,
	      void (T::* FPTR)() const>
void PluggableArchCall(T& w)
{
	(w.*FPTR)();
}

int main()
{
	// pointer to member pointing to data member 'm_val'
	int Widget::* ptr = &Widget::m_val;

	Widget w { 10 };
	// use `ptr` to point to the target data member of the Widget object we want to compare in this line
	assert(w.*ptr == 10);

	void (Widget::* fPtr)() const = &Widget::Foo;
	void (Widget::* bPtr)() const = &Widget::Bar;

	(w.*fPtr)();
	(w.*bPtr)();

	PluggableArchCall<Widget, &Widget::Foo>(w);
	PluggableArchCall<Widget, &Widget::Bar>(w);
	
	return 0;
}
