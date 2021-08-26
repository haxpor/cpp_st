#pragma once

class Base
{
public:
	virtual void Foo() = 0;
};

class Widget : public Base
{
public:
	virtual void Foo() override;
};
