/**
 * Demonstrate that a class can inherit from abstract class without a need to implement all
 * pure functions.
 *
 * So we can inherit in hop by hop. But the class in between cannot be used as concrete class as
 * it still need to implement the missing pure functions.
 */
#include <iostream>

struct IWidget
{
	virtual void foo() = 0;
	virtual void bar() = 0;
};

struct IWidgetBase : public IWidget
{
	virtual void foo() override
	{
		std::cout << "foo" << std::endl;
	}
};

struct ImplementedClassB : public IWidgetBase
{
	virtual void bar() override
	{
		std::cout << "bar" << std::endl;
	}
};

int main()
{
	ImplementedClassB wb;
	wb.foo();
	wb.bar();

	IWidget* w_ptr = new ImplementedClassB{};
	w_ptr->foo();
	w_ptr->bar();
	delete w_ptr;

	// The following won't work as bar() is still pure (abstract function) and not implemented yet
	//IWidgetBase wa;

	return 0;
}
