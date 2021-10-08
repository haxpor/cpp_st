/**
 * Small prove-of-concept of relationship between deleter and destructor function
 * of the class initialized or wrapped with std::shared_ptr.
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
	void operator()(Widget* ptr)
	{
		std::cout << "CustomDeleter::operator() called\n";
		delete ptr;
	}
};

struct CustomDeleterGetter
{
	static CustomDeleter* GetCustomDeleter()
	{
		static CustomDeleter s_customDeleter;
		return &s_customDeleter;
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
		auto ptr = std::shared_ptr<Widget>(new Widget(1), *CustomDeleterGetter::GetCustomDeleter());
	}
	return 0;
}
