/**
 * More test on std::weak_ptr.
 * Inspired by https://docs.microsoft.com/en-us/cpp/cpp/how-to-create-and-use-weak-ptr-instances?view=msvc-160
 */

#include <memory>
#include <vector>
#include <iostream>

struct Widget
{
	Widget(int _id):
		id(_id),
		status(true)	// every construction will mark status as strue
	{
		std::cout << "ctor: " << id << "\n";
	}

	~Widget()
	{
		std::cout << "dtor: " << id << "\n";
	}

	void CheckStatus() const
	{
		std::cout << "ID: " << id << ", " << "Status: " << std::boolalpha << status << "\n";
		for (std::size_t i=0; i < others.size(); ++i)
		{
			if (std::shared_ptr<Widget> lw = others[i].lock())
			{
				std::cout << "  - others[" << i << "]: ID: " << lw->id << ", expired: " << std::boolalpha << others[i].expired() << "\n";
			}
		}
	}
	
	int id;
	bool status;
	std::vector<std::weak_ptr<Widget>> others;
};

int main()
{
	std::vector<std::shared_ptr<Widget>> widgets = {
		std::make_shared<Widget>(1),
		std::make_shared<Widget>(2),
		std::make_shared<Widget>(3)
	};

	for (std::size_t i=0; i<widgets.size(); ++i)
	{
		for (std::size_t j=0; j<widgets.size(); ++j)
		{
			if (j != i)
				(*widgets[i]).others.push_back(std::weak_ptr<Widget>(widgets[j]));
		}
	}

	for (const auto& w : widgets)
	{
		std::cout << "use_count = " << w.use_count() << "\n";
		w->CheckStatus();
	}
	return 0;
}
