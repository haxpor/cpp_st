#include <iostream>
#include <cassert>
#include <memory>

template <typename T>
struct SubWidget
{
	SubWidget()
	{
		std::cout << "SubWidget ctor\n";
	}

	SubWidget(T i)
		: m_val(i)
	{
		std::cout << "SubWidget ctor(" << m_val << ")\n";
	}

	SubWidget(const SubWidget& other)
		: m_val(other.m_val)
	{
		std::cout << "SubWidget copy ctor called\n";
	}

	SubWidget(SubWidget&& other)
		: m_val(other.m_val)
	{
		std::cout << "SubWidget move ctor called\n";
	}

	T m_val;
};

template <typename T>
struct Widget
{
	Widget()
	{
		std::cout << "Widget ctor()\n";
	}

	Widget(const Widget& w)
		: m_member(w.m_member)
	{
		std::cout << "Widget copy ctor called\n";
	}

	Widget(Widget&& w)
		: m_member(std::move(w.m_member))
	{
		std::cout << "Widget move ctor called\n";
	}

	SubWidget<T> m_member {1};
};

template <typename T>
static Widget<T> CreateWidget()
{
	auto w = Widget<T>();
	w.m_member.m_val = 10;
	return w;
}

int main()
{
	auto w = CreateWidget<int>();
	assert(w.m_member.m_val == 10);
	return 0;
}
