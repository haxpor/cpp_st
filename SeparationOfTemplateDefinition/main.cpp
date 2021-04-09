/**
 * Demonstrate separation of template definition from its declaration
 *
 * The thing is whenever your non-template related implementation file e.g. main.cpp, anotherModule.cpp
 * get compiled, it won't be compiled at the same time as template definition (template's implementation file)
 * unless you do uber compilation. Thus compiler won't see the template type in actual usage e.g. TemplateLib<int> at the same time
 * of template definition in order to instantiate the template for users to use.
 *
 * Thus to solve such issue, we can explicitly instantiate template class ourselves (see TemplateLit.cpp).
 * This allows us to separate template's declaration and definition.
 *
 * Extra note:
 * 'extern template' is another approach introduced in C++11 but its main goal
 * is to reduce the compilation time as it reduces redandant template compilation,
 * it's just like e.g. 'extern int' as there is just one definition of it.
 * Still we have to explicitly instantiate the template class like we did in TemplateLib.cpp.
 */
#include "TemplateLib.h"

int main()
{
	TemplateLib<int> myTL;
	myTL.Foo(10);
	return 0;
}
