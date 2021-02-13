#pragma once

class Widget
{
public:
	Widget();
	Widget(int data);
	~Widget();

	int GetData() const;

private:
	// these two functions are intentionally marked "private", and unimplemented
	// thus who uses it even its own class will produce linker error from compiler
	Widget(const Widget&);
	Widget& operator=(const Widget&);

private:
	int m_data;
};
