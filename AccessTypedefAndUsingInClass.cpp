/**
 * Demonstrate accessing 'typedef' and 'using' from class object.
 * Don't mind using [[maybe_unused]] (c++17) to suppress unused variables.
 */
struct Widget
{
	typedef int MyInt;
	using MyAnotherInt = int;
};

int main()
{
	[[maybe_unused]] Widget::MyInt myVar;
	[[maybe_unused]] Widget::MyAnotherInt myVar2;
	return 0;
}
