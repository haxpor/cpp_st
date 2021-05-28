/**
 * std::unique_ptr's copy constructor, and copy assignment operator are deleted.
 * Thus when we try grab std::unique_ptr from container, we need to pass it by reference.
 * 
 * Inspired by https://docs.microsoft.com/en-us/cpp/cpp/how-to-create-and-use-unique-ptr-instances?view=msvc-160
 */
#include <memory>
#include <vector>
#include <iostream>

struct Widget
{
	Widget(const char* name1, const char* name2):
		m_name1(name1),
		m_name2(name2)
	{}

	const char* m_name1;
	const char* m_name2;
};

int main()
{
	std::vector<std::unique_ptr<Widget>> widgets;

	widgets.push_back(std::make_unique<Widget>("Widget1_fname", "Widget1_lname"));
	widgets.push_back(std::make_unique<Widget>("Widget2_fname", "Widget2_lname"));
	widgets.push_back(std::make_unique<Widget>("Widget3_fname", "Widget3_lname"));

	for (const auto& w : widgets)	// cannot use 'for (auto w : widgets)'
	{
		std::cout << w->m_name1 << " " << w->m_name2 << "\n";
	}

	return 0;
}
