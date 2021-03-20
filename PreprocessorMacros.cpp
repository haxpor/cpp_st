#include <iostream>

// this one as seen in Large Scale C++ Software Design. It is actually a c-stryle comment.
#define GLUE(X,Y) X/**/Y

// concatenate operator for preprocessor macros
#define GLUE2(X,Y) X ## Y

// stringify operator for preprocessor macros
#define STRINGIFY(X) #X

// custom solution trying to get :: into concatenation inside preprocessor macro
#define GLUE3(X,Y) X::Y

int main()
{
	GLUE(std::,cout) << "Hello world" << std::endl;

	// TODO: Uncomment this to see compilation error as macro's concatenation operator doesn't able to part ::
	//GLUE2(std::,cout) << "Hello world" << std::endl;
	
	GLUE3(std,cout) << "Hello world" << std::endl;
	std::cout << STRINGIFY(My name is Wasin) << std::endl;

	return 0;
}
