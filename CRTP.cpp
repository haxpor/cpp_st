/**
 * Validate CRTP pattern
 */
#include <iostream>
#include <type_traits>

struct IBase
{
	virtual void Common() = 0;
	virtual void Specific() = 0;
};

template <typename T>
struct CRTP : public IBase
{
	virtual void Common() override
	{
		std::cout << "CRTP::Common()" << std::endl;
	}

	virtual void Specific() override
	{
		static_cast<T*>(this)->SpecificImpl();
	}

private:
	void SpecificImpl()
	{
		std::cout << "CRTP::SpecificImpl()" << std::endl;
	}
};

struct Derived1 : public CRTP<Derived1>
{
private:
	void SpecificImpl()
	{
		std::cout << "Derived1::SpecificImpl()" << std::endl;
	}

	// to allow CRTP to call internal function e.g. SpecificImpl() which should not be exposed publicly
	// note: to my surprise, we can just use 'CRTP' which is the class template name here which is not a type
	friend CRTP<Derived1>;
};

int main()
{
	Derived1 d1;
	d1.Common();
	d1.Specific();
	static_assert(std::is_base_of_v<IBase, Derived1>, "Derived1 must be sub-class of IBase");
	static_assert(std::is_base_of_v<CRTP<Derived1>, Derived1>, "Derived1 must be sub-class of CRTP");
	return 0;
}
