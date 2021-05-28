/**
 * More tests for std::shared_ptr.
 * Inspired by https://docs.microsoft.com/en-us/cpp/cpp/how-to-create-and-use-shared-ptr-instances?view=msvc-160
 */

#include <iostream>
#include <vector>
#include <memory>
#include <cassert>

struct WidgetBase
{
	virtual ~WidgetBase() = default;
};

struct Widget1 : public WidgetBase
{
	Widget1(int val, const char* name):
		WidgetBase(),
		m_val(val),
		m_name(name)
	{}
	virtual ~Widget1() { std::cout << "dtor(Widget1): " << m_val << ", " << m_name << "\n"; }

	int m_val;
	const char* m_name;
};

struct Widget2 : public WidgetBase
{
	Widget2(int size, float val):
		WidgetBase(),
		m_size(size),
		m_val(val)
	{}
	virtual ~Widget2() { std::cout << "dtor(Widget2): " << m_size << ", " << m_val << "\n"; }

	int m_size;
	float m_val;
};

// argument is by copy
static void PrintWidget1(const Widget1 copy)
{
	std::cout << "m_val: " << copy.m_val << ", m_name: " << copy.m_name << "\n";
	// after this, a copy instance will be destroyed and thus immediately decrement use_count back to 1, see console output of "dtor(Widget1)..."
}

// argument is by pointer
static void PrintWidget1(const Widget1* ptr)
{
	std::cout << "m_val: " << ptr->m_val << ", m_name: " << ptr->m_name << "\n";
}

// argument is by reference
static void PrintWidget2(const Widget2& w)
{
	std::cout << "m_size: " << w.m_size << ", m_val: " << w.m_val << "\n";
}

int main()
{
	std::vector<std::shared_ptr<WidgetBase>> widgets {
		std::make_shared<WidgetBase>(),
		std::make_shared<Widget1>(1, "Widget1_1"),
		std::make_shared<Widget1>(2, "Widget1_2"),
		std::make_shared<Widget2>(10, 10.5),
		std::make_shared<Widget2>(20, 20.5)
	};

	// before end of life, number of shared_ptr owns it (use_count()) should just be 1 for each
	for (std::size_t i=0; i<widgets.size(); ++i)
	{
		assert(widgets[i].use_count() == 1);
	}

	// test local scope lifetime
	{
		std::shared_ptr<WidgetBase> wAnother = widgets[4];
		assert(widgets[4].use_count() == 2);
		assert(wAnother.use_count() == 2);
	}
	assert(widgets[4].use_count() == 1);

	// test range base via copy
	// ref count is incremented for each
	for (const auto w : widgets)
	{
		assert(w.use_count() == 2);
	}

	// test range base via reference
	// ref count is **not** incremented
	for (const auto& w : widgets)
	{
		assert(w.use_count() == 1);
	}

	// test getting and sending underlying pointer of std::shared_ptr to function
	PrintWidget1(*std::static_pointer_cast<const Widget1>(widgets[1]));
	PrintWidget1(std::static_pointer_cast<const Widget1>(widgets[1]).get());
	PrintWidget2(*std::static_pointer_cast<const Widget2>(widgets[3]));

	return 0;
}
