#include "Widget.h"

Widget::Widget() :
	m_data(0)
{

	// use -DDEMON_CLASS for compiler's option (GCC/Clang), or /D for MSVC
	// to demonstrate the linker error from usage within the class
#ifdef DEMON_CLASS
	Widget localDummy (3);
	// this line will trigger linker error from compiler
	// even at private as marked for such function in the header file, but it's
	// also unimplemented, thus linker will detect this
	//
	// The cure is to also mark it "= default" even at private, but the intention
	// for us is to disabled constructing in such way at all even the class uses
	// it by itself.
	Widget anotherLocalDummy (localDummy);	// triger private unimplemented function
#endif
}

Widget::Widget(int data) :
	m_data(data)
{
	// intentionally left blank
}

Widget::~Widget()
{
	// intentionally left blank
}
