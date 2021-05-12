/**
 * Study template metaprogramming for policy pattern with a couple of styles in declaration.
 *
 * BackingIntType and BackingDoubleType are underlying types used by those object holder i.e. ObjectIntCreator, and ObjectDoubleCreator.
 * But there is one underlying type which is not used anywhere BackingStringType. This type will be used to demonstrate against the constraints
 * we have implemented in the template as seen via std::enable_if.
 *
 * WidgeIntManager, or other Widget...Manager classes are there with pre-defined policy at compile time
 * to do stuff according to such input type for its own logic code.
 *
 * Two styles of declaration are there to declare all as template parameters, or bake some inside the template definition.
 *
 * Notice
 *
 * 1. template template <class> - there is no template parameter naming for `class`
 * 2. Two styles of declarations 
 *
 * Compile with
 * g++ -std=c++17 -Wall -Wextra -pedantic TemplatePolicy.cpp
 */
#include <type_traits>
#include <cassert>

struct BackingIntType
{
	// NOTE: we could use `consteval` to strongly signify that this constructor must be evaluated at compile time, but
	// it's available in c++20 for gcc v.10 onwards
	BackingIntType():
		m_val(0)
	{}
	BackingIntType(int v):
		m_val(v)
	{}

	int m_val;
};

struct BackingDoubleType
{
	BackingDoubleType():
		m_val(0.0)
	{}
	BackingDoubleType(double v):
		m_val(v)
	{}

	double m_val;
};

struct BackingStringType
{
	BackingStringType():
		m_val(nullptr)
	{}

	BackingStringType(const char* v):
		m_val(v)
	{}


	const char* m_val;
};

template <class T, typename BACKING_TYPE=int>
struct ObjectIntCreator
{
	using backing_type = BACKING_TYPE;

	// NOTE: I always want to enable it via a type template parameter (which in my opinion the cleanest way, way no.5 as seen in https://en.cppreference.com/w/cpp/types/enable_if)
	// but it mostly will fail, so I tend to choose other ways like this; via returning type
	static typename std::enable_if_t<std::is_constructible_v<T, int>, T>
	CreateObject(backing_type v)
	{
		return T(v);
	}
};

template <class T, typename BACKING_TYPE=double>
struct ObjectDoubleCreator
{
	using backing_type = BACKING_TYPE;

	static typename std::enable_if_t<std::is_constructible_v<T, double>, T>
	CreateObject(backing_type v)
	{
		return T(v);
	}
};

// -- Style 1 declaration
// NOTE: BACKINGTYPE is not needed, but can be specified
template <template <class DUMMY_BACKINGTYPE> class ObjectTypePolicy>
struct WidgetIntManager : public ObjectIntCreator<BackingIntType>
{
	void Assert()
	{
		assert(CreateObject(1).m_val == 1);
	}
};

template <template <class DUUMY_BACKINGTYPE> class ObjectTypePolicy>
struct WidgetDoubleManager : public ObjectDoubleCreator<BackingDoubleType>
{
	void Assert()
	{
		assert(CreateObject(2.0).m_val == 2.0);
	}
};

typedef WidgetIntManager<ObjectIntCreator> WidgetIntHelper;
typedef WidgetDoubleManager<ObjectDoubleCreator> WidgetDoubleHelper;

// -- Style 2 declaration
template <template <class> class ObjectTypePolicy, class BACKINGTYPE>
struct WidgetIntManager2 : public ObjectTypePolicy<BACKINGTYPE>
{
	void Assert()
	{
		// NOTE: we need static_cast<....> here in order to associate CreateObject() to depend on BACKINGTYPE so compiler knows from which type such function will be called from
		assert(static_cast<ObjectTypePolicy<BACKINGTYPE>*>(this)->CreateObject(1).m_val == 1);
	}
};

template <template <class> class ObjectTypePolicy, class BACKINGTYPE>
struct WidgetDoubleManager2 : public ObjectTypePolicy<BACKINGTYPE>
{
	void Assert()
	{
		assert(static_cast<ObjectTypePolicy<BACKINGTYPE>*>(this)->CreateObject(2.0).m_val == 2.0);
	}
};

typedef WidgetIntManager2<ObjectIntCreator, BackingIntType> WidgetIntHelper2;
typedef WidgetDoubleManager2<ObjectDoubleCreator, BackingDoubleType> WidgetDoubleHelper2;

int main()
{
	{
		WidgetIntHelper wInt;
		wInt.Assert();

		WidgetDoubleHelper wDouble;
		wDouble.Assert();
	}

	{
		WidgetIntHelper2 wInt;
		wInt.Assert();

		WidgetDoubleHelper2 wDouble;
		wDouble.Assert();

		// TODO: set value of next line to 1 to experience the compiler's error against our template's constraints
#define EXPERIENCE_COMPILER_ERROR 0
#if EXPERIENCE_COMPILER_ERROR == 1
		// Object holder is int type, but underlying backing type is c-string
		ObjectIntCreator<BackingStringType> wrongObject;
		wrongObject.CreateObject("dummy");

		WidgetDoubleManager2<ObjectIntCreator, BackingStringType> wrongWidget;
		wrongWidget.Assert();
#endif
	}

	return 0;
}
