#pragma once

#include <iostream>

namespace Detail
{
	namespace AnotherLevel
	{
		enum class Numbers
		{
			ONE = 1,
			TWO
		};

		struct Util
		{
			static void foo()
			{
				std::cout << "foo()" << std::endl;
			}

			static void trycall()
			{
				std::cout << "trycall()" << std::endl;
			}
		};
	};
};

class Widget
{
	// not possible as using at class scope can only be used
	// for member data, not arbitrary names
	//using Detail::AnotherLevel::Util;

public:
	void begin()
	{
		using namespace Detail::AnotherLevel;
		Util::foo();

		using Detail::AnotherLevel::Numbers;
		std::cout << "TWO: " << static_cast<int>(Numbers::TWO) << std::endl;
	}
};
