#pragma once

class Widget;

class Lib
{
public:
	// Pay attention to this line as return type doens't require you to physically
	// add #include for corresponding header file. We can forward declare such type.
	//
	// This is validated by compilation passed for this component. See Lib.o target in Makefile.
	Widget Foo();
};
