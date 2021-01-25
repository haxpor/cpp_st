/**
 * Demonstrate that non-trivial object cannot be passed (with implicitly data type conversion)
 * into variadic function especially with clang which will shout out error of
 *
 * "error: cannot pass object of non-trivial type .... (aka '....) through variadic function; call will abort at runtime [-Wnon-pod-varargs]
 */
#include <iostream>
#include <cstdarg>
#include <cstring>
#include <cstdio>

// variadic function which usually trigger an issue that clang cannot implicitly convert
// type T to const char* even we've defined casting operator.
static void FreeLog(const char* format, ...)
{
	va_list arglist;
	va_start(arglist, format);
	std::vprintf(format, arglist);
	va_end(arglist);	
}

template<class T, size_t SIZE>
struct MyStringWrapper
{
public:
	typedef T                    value_type;
	typedef const value_type*    const_str;
public:

	// this is not necessary to make this class non-trivial
	// more weight on destructor
	//MyStringWrapper()
	//{
	//}
	
	// NOTE: even with empty destructor, this makes the class non-trivial now which
	// makes it not possible to pass object with implicitly data type convert into variadic function especially in clang compiler.
	//
	// It has no requirement to also have non-trivial constructor
	//
	// Uncomment this destructor lines to pass the compiler's error.
	~MyStringWrapper()
	{
	}

	MyStringWrapper(const_str str)
	{
		std::strcpy(strBuf, str);
	}

	operator const_str() const { return strBuf; }

private:
	value_type strBuf[SIZE];	
};

typedef MyStringWrapper<char, 512> MyString;

int main()
{
	MyString myStr("hello world");
	// this line is totally fine
	std::cout << "String: " << myStr << std::endl;

	FreeLog("String: %s\n", myStr);
	return 0;
}
