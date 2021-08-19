#include "another2.h"
#include "Lib.h"

#include <iostream>
#include <memory>

void DoSomething2()
{
	GetWidgetInstance()->m_val += 10;
}

bool ValidateAddress2(const Widget* w)
{
	return std::addressof(*w) == std::addressof(*GetWidgetInstance());
}

void PrintAddress2()
{
	std::cout << "Another2: " << std::addressof(*GetWidgetInstance()) << "\n";
}
