/**
 * Demonstrate that non-trivial object cannot be passed (with implicitly data type conversion)
 * into variadic function especially with clang which will shout out error of
 *
 * "error: cannot pass object of non-trivial type .... (aka '....) through variadic function; call will abort at runtime [-Wnon-pod-varargs]
 *
 * Compile it with
 *
 * "clang++ -std=c++17 -Wall -Wextra ClangImplicitConversion.cpp"
 *
 * although -Wall -Wextra might not be necessary, and we can force it to proceed on with it with -Wno-non-pod-varargs but that will crash (core dumped) finally so not much help.
 *
 * But this won't shout out any error message on GCC, or MSVC.
 * Unless turn on warning for GCC with -Wconditionally-supported.
 */
#include <cstdarg>
#include <cstring>
#include <string>
#include <cstdio>
#include <type_traits>

// variadic function which usually trigger an issue that clang cannot implicitly convert
// type T to const char* even we've defined casting operator.
static void FreeLog(const char* format, ...)
{
	va_list arglist;
	va_start(arglist, format);
	std::vprintf(format, arglist);
	va_end(arglist);	
}

struct Pod
{
	double foo;
	const char* bar;

	operator const char*() const { return bar; }
};

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
	// TODO: Comment this destructor lines to pass the compiler's error.
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
	// 1: this line is totally fine
	FreeLog("1: %f %s\n", 10.0, "Helloworld");

	// 2: trivial object (or per se POD)
	static_assert(std::is_trivial<Pod>::value, "Pod structure must be trivial type");
	Pod st { 10.0, "Bar text" };
	FreeLog("2: %f %s\n", st.foo, st);

	// 3: non-trivial object
	// now it would be a problem for clang. For  GCC/MSVC would be the case, if we turn on such warning as well.
	static_assert(!std::is_trivial<MyString>::value, "MyString must be non-trivial type");
	// this check is not necessary as trivially-copyable at least requires type to be trivial type, but no harm to add
	static_assert(!std::is_trivially_copyable<MyString>::value, "MyString must be non-trivially-copyable type");
	MyString myStr("Hello world");
	// TODO: comment this line to be able to pass the compilation
	FreeLog("3: %s\n", myStr);

	return 0;
}
