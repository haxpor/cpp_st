#include "TemplateLib.h"
#include <iostream>

template <typename T>
void TemplateLib<T>::Foo(T val)
{
	std::cout << "val is " << val << std::endl;
}

// instantiate template
// note: see 3 things as required to have as to why compiler needs to see both declaration and definition fo template
// so we explicitly instantiate template class as expected for users to be using here (it needs to be in the same place as of template's definition)
template class TemplateLib<int>;
