/**
 * Demonstrate template implementation that derive from non-template class.
 * Combine with template specialization test validate two things
 *
 * 1. whether we can still call the exposed member function from such parent class in derived specialized class template?
 * Ans: Yes.
 * 2. can we access member variables or member functions declared/defined in generic class template declaration?
 * Ans: No. Each specilization template is indepedent from each other, and has its own declaration that compiler will use. It doesn't source in from generic class template declaration.
 */
#include "Consumer.h"

int main()
{
	// TODO: Uncomment the following two lines to see effect of unimplemented function
	//Widget<char> w;
	//w.PrintHello();
	
	Widget<int> wInt(10);
	wInt.PrintCommonString();
	std::cout << "Widget<int>'s value: " << wInt.GetIVal() << '\n';

	Widget<std::string> wStr("Hello world");
	wStr.PrintCommonString();
	std::cout << "Widget<std::string>'s value: " << wStr.GetStringVal() << '\n';
	
	return 0;
}
