#pragma once
#include <iostream>
#include <cassert>
#include <type_traits>
#include <string>

// Interface that template class will derive from
struct IWidget
{
	virtual void PrintCommonString() { std::cout << "IWidget, something common\n"; }

	virtual void PrintHello() = 0;
	virtual int GetIVal() = 0;
	virtual std::string GetStringVal() = 0;

protected:
	virtual ~IWidget() {}
};

// Generic template implementation
template <typename T>
class Widget : public IWidget
{
public:
	using value_type = std::remove_reference_t<T>;

	Widget(value_type v)
	{
		assert(false && "You should not be using this type Widget");
	}

	virtual void PrintHello() override
	{
		assert(false && "Function not implemented");
	}

	virtual int GetIVal() override
	{
		assert(false && "Function not implemented");
		return -1; // should not reach here
	}

	virtual std::string GetStringVal() override
	{
		assert(false && "Function not implemented");
		return ""; // should not reach here
	}
};

// Specialization template - int
template <>
class Widget<int> : public IWidget
{
public:
	Widget(int v):
		m_value(v)
	{
	}

	virtual void PrintHello() override
	{
		std::cout << "Hello from Widget<int>\n";
	}

	virtual int GetIVal() override
	{
		return m_value;
	}

	virtual std::string GetStringVal() override
	{
		return std::to_string(m_value);
	}

private:
	int m_value;
};

// Specialization template - string
template <>
class Widget<std::string> : public IWidget
{
public:
	Widget(const std::string& str)
		: m_value(str)
	{
	}

	Widget(const char* str)
		: m_value(str)
	{
	}

	virtual void PrintHello() override
	{
		std::cout << "Hello from Widget<std::string>\n";
	}

	virtual int GetIVal() override
	{
		assert(false && "Widget<std::string> should not be using GetVal()");
		return -1; // should not reach here
	}

	virtual std::string GetStringVal() override
	{
		return m_value;
	}

private:
	std::string m_value;
};
