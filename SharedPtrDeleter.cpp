/**
 * Small prove-of-concept of relationship between deleter and destructor function
 * of the class initialized or wrapped with std::shared_ptr.
 *
 * Additional test cases are added for situation that we need to have a virtual
 * functor/function to handle the deletetion logic for shared_ptr's deleter.
 * Notice that we cannot expect virtual resolution to work.
 */
#include <memory>
#include <iostream>

struct Widget
{
	int val;

	Widget(int _val)
		: val(_val)
	{
	}

	~Widget()
	{
		std::cout << "~Widget()\n";
	}
};

struct CustomDeleter
{
	virtual void operator()(Widget* ptr)
	{
		std::cout << "CustomDeleter::operator() called\n";
		delete ptr;
	}
};

struct DerivedCustomDeleter : public CustomDeleter
{
	virtual void operator()(Widget* ptr) override
	{
		std::cout << "DerivedCustomDeleter::operator() called\n";
		delete ptr;
	}
};

struct DeleterGetter
{
	static CustomDeleter* GetCustomDeleter()
	{
		static CustomDeleter s_deleter;
		return &s_deleter;
	}

	static CustomDeleter* GetDerivedDeleter()
	{
		static DerivedCustomDeleter s_deleter;
		return &s_deleter;
	}
};

int main()
{
	{
		auto ptr = std::shared_ptr<Widget>(new Widget(1), [](auto p) {
					std::cout << "Custom deleter called for Widget(" << p->val << ")\n";	// do any custom deleting logic
					delete p;	// we still have to manually delete the pointer on heap
								// if we miss this line, then destructor won't be called
				});;
	}

	{
		auto ptr = std::shared_ptr<Widget>(new Widget(1), *DeleterGetter::GetCustomDeleter());
	}

	// this will still call the base; CustomDeleter as for destructor, it will
	// calls only for the definitions it know at that point in time
	// see https://stackoverflow.com/a/962148/571227
	{
		auto ptr = std::shared_ptr<Widget>(new Widget(1), *DeleterGetter::GetDerivedDeleter());
	}
	return 0;
}
