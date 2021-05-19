/**
 * Test to access 'using' aliased type in base class
 */
#include <type_traits>

template <class T>
struct WidgetBase
{
	using base_t = T;
	using value_t = std::remove_reference_t<base_t>;
};

template <class T>
struct Widget : public WidgetBase<T>
{
	// we can access 'using' aliased type with this syntax
	typename WidgetBase<T>::value_t m_val;
};

int main()
{
	Widget<int> w;
	w.m_val = 10;
	return 0;
}
