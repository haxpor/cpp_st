// Demonstrate casting from const reference/rvalue to constant pointer
#include <iostream>

struct Widget
{
	int data;
};

// forward declared
void lowerFunc(const Widget*);

void upperFunc(Widget&& w)
{
	lowerFunc(static_cast<const Widget*>(&w));
}

void upperFunc2(const Widget& w)
{
	lowerFunc(static_cast<const Widget*>(&w));
}

void lowerFunc(const Widget* w)
{
	if (w)
		std::cout << w->data << std::endl;
}

int main()
{
	upperFunc(Widget{15});

	Widget w{200};
	upperFunc2(w);
	return 0;
}
