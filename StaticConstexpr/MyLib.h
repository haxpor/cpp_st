#pragma once

#include <iostream>
#include <memory>

enum class MyLibValue
{
	Value1=10,
	Value2
};

struct MyLib
{
	// compiler will most likely treat this as 'inline' so it won't allocate memory space for it
	static constexpr MyLibValue s_myLibDefaultValue = MyLibValue::Value2;

	static MyLibValue GetMyLibValue()
	{
		return s_myLibDefaultValue;
	}

	static bool CheckMyLibValue(MyLibValue against)
	{
		return s_myLibDefaultValue >= against;
	}

	static void PrintValueAddress()
	{
		//std::cout << "MyLib: " << std::addressof(s_myLibDefaultValue) << "\n";
		std::cout << "MyLib: " << static_cast<int>(s_myLibDefaultValue) << "\n";
	}

	void PrintSomething() const;
};
