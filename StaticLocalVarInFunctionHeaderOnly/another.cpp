#include "another.h"
#include "Lib.h"

#include <iostream>
#include <memory>

void DoSomething()
{
	GetWidgetInstance()->m_val += 10;
}

bool ValidateAddress(const Widget* w)
{
	return std::addressof(*w) == std::addressof(*GetWidgetInstance());
}

void PrintAddress()
{
	std::cout << "Another: " << std::addressof(*GetWidgetInstance()) << "\n";
}
