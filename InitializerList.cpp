/**
 * Prove of https://stackoverflow.com/a/9903262/571227
 * That even without initializer list for such data member, behind the scene
 * compiler will add one for us.
 *
 * Whenever we don't have Param1() (default constructor without any parameter),
 * then compiler will generate compile error.
 */
#include <iostream>

struct Param1
{
	Param1()
	{
		std::cout << "Param1() <---- automatically called by compiler for our empty initializer list\n";
	}

	Param1(int _dummy)
	{
		std::cout << "Param1(" << _dummy << ")\n";
	}
};

struct Widget
{
	Widget(Param1 _p1)	// at this location, compiler will automatically add initializer list for our data member i.e. Param1
	{
		std::cout << "before Widget() code\n";
		p1 = _p1;
		std::cout << "after Widget() code\n";
	}

	Param1 p1;
};

int main()
{
	Widget w (Param1(1));
	return 0;
}
