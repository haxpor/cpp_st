/**
 * Demonstrate how to emit only the instance of function template and elide those unused.
 *
 * Reasons about this, compiler doesn't know that such instances of function template won't be used in another translation unit, thus it won't remove
 * the emitting of its symbols. What we can do is doing the following
 *
 * - declare `static` in front of the function template (repeat: not the specialization of function template)
 * - wrap those declarations inside anonymous namespace so it will make sure that other translation units won't be calling them
 * - declare `inline` in front of the template function so compiler will inject such code inlined whenever it needs to
 *
 * Usually we will need to specify optimization level ideally with -Os, or -O2/-O3.
 */
#include <iostream>

enum class EnumWidget
{
	One,
	Two,
	Three
};

// function template
// In this example, we put `static` to make compiler emit only what used in this source file.
template <EnumWidget> static const char* GetWidgetEnumStr()  { return nullptr; }

// specialization of function template
template <> const char* GetWidgetEnumStr<EnumWidget::One>() { return "One"; }
template <> const char* GetWidgetEnumStr<EnumWidget::Two>() { return "Two"; }
template <> const char* GetWidgetEnumStr<EnumWidget::Three>() { return "Three"; }

int main()
{
	std::cout << GetWidgetEnumStr<EnumWidget::One>() << std::endl;
	return 0;
}
