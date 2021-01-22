/**
 * Prove of concept that non-immediate-first level of derived class needs not to also define virtual
 * for its destructor to make destructor function works and called properly.
 *
 * Derived1 didn't use `virtual` for its destructor but Derived2 still be able to call Base's destructor properly.
 */
#include <iostream>

class Base
{
public:
	virtual ~Base() { std::cout << "~Base()\n"; }
};

class Derived1 : public Base
{
public:
	~Derived1() { std::cout << "~Derived()1\n"; }
};

class Derived2 : public Derived1
{
public:
	~Derived2() { std::cout << "~Derived()2\n"; }
};

int main()
{
	Base *d2 = new Derived2();
	delete d2;
	return 0;
}
