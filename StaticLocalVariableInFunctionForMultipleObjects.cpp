/**
 * Prove-of-concept that static local variable to function scope has only one instance
 * for the class although we've created multiple objects from the same class.
 */
#include <iostream>
#include <memory>

struct Widget
{
public:
	void Foo()
	{
		static int s_num;
		s_num++;

		std::cout << std::addressof(s_num) << std::endl;
	}
};

int main()
{
	Widget w1;
	Widget w2;

	w1.Foo();
	w2.Foo();
	return 0;
}
