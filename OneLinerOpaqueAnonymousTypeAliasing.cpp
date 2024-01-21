/**
 * This inspired from seeing source code of pdfium
 * which has declaration like this
 *
 * typedef struct fpdf_document_t__* FPDF_DOCUMENT;
 *
 * It looks like mystery that where is fpdf_document_t__
 * definition? There is nothing elsewhere within pdfium
 * source code.
 *
 * But actually such line combines defining the struct, and
 * at the same time aliasing a new type to pointer of it.
 *
 * Above works for both C, and C++. But if you want to omit
 * using "struct" in C++, thus you have to explicitly define
 * such type that we alias to first via the following code
 *
 * struct fpdf_document_t {};
 * using FPDF_DOCUMENT = fpdf_document_t*;
 *
 * Anyhow without using "struct" is much more forgiving in
 * this case.
 *
 * -- Why? --
 *
 * I believe pdfium source code did that in order to abstract
 * multi-lib API, accommodate opaque data passing across APIs withing pdfium itself.
 * As well it allows the point of opportunity to specialize
 * on such anonymous type (fpdf_document_t__) so in certain
 * case working with FPDF_DOCUMENT, at lower level layer,
 * there can be a code that handles specifically towards such opaque type. It won't be possible if all is "void*" that new
 * type aliases to.
 */
#include <iostream>
#include <type_traits>

/**
 * 1. C++-based declaration
 * See C-based declaration version below.
 * It is similar without keyword "struct" as C++
 * doesn't need it.
 */
using MyStruct = struct __mystruct_t_*;

// (explicit) or use the following version
// as C++ doesn't need keyword "struct" to refer to struct and
// if we would like to omit it when "using".
//struct __mystruct_t_ {};
//using MyStruct = __mystruct_t_*;

// 2. C-based declatation
//typedef struct __mystruct_t_* MyStruct;

template<typename T>
void Foo()
{
	std::cout << "Generic" << std::endl;
}

template<>
void Foo<MyStruct>()
{
	std::cout << "MyStruct type" << std::endl;
}

template<>
void Foo<__mystruct_t_>()
{
	std::cout << "__mystruct_t type" << std::endl;
}

int main()
{
	Foo<MyStruct>();
	Foo<__mystruct_t_*>();
	Foo<__mystruct_t_>();	// allow point of opportunity to specialize on this type. It resolves to different specialized template. It won't be possible if the tye that new type aliases to is "void*".
	Foo<void>();

	std::cout << std::boolalpha<< std::is_same_v<MyStruct, __mystruct_t_*> << std::endl;
	return 0;
}
