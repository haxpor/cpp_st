/**
 * Test sending in function or functor as template's argument.
 *
 * Tested on gcc 9.3.0, clang++ 9.0.1-12, and MSVC 19.16.27045 for x64
 */
#include <type_traits>
#include <cassert>
#include <iostream>

struct IWidget
{
	virtual void SetVal(int) = 0;
	virtual int GetVal() const = 0;
};

// NOTE: Compile time check for callback against nullptr is needed as template is instantiated at compile time
// this is to avoid compile warning of "the address of 'void Callback1(IWidget*)' will never be NULL". That'd solve a redundant check.
constexpr bool IsNull(void Callback(IWidget*)=nullptr) {
	return Callback == nullptr;
}

// --- Approach 1 for clear signature of callback --- //
// NOTE: It's non-type template parameter for Callback(IWidget*).
template <typename TYPE, void Callback(IWidget*)=nullptr>
class Widget : public IWidget
{
public:
	using value_type = TYPE;
	using base_type = std::remove_reference_t<value_type>;

	virtual void SetVal(int val) override
	{
		m_val = static_cast<int>(val);
		if (!IsNull(Callback))
			Callback(this);
	}

	virtual int GetVal() const override
	{
		return static_cast<int>(m_val);
	}

private:
	base_type m_val;
};

static void Callback1(IWidget* w)
{
	assert(w->GetVal() == 1);
}

// --- Approach 2 for type template argument --- //
// NOTE: Use template<auto>. It has the same effect as of approach 1 just that we have no need to explicitly specify the type of template's argument function.
// NOTE2: It's non-type template parameter for Callback.
// CAVEAT: We cannot introduce 'auto Callback=nullptr' as we cannot perform Callback(this) later because we didn't know its clear signature.
template <typename TYPE, auto Callback>
class Widget2 : public IWidget
{
public:
	using value_type = TYPE;
	using base_type = std::remove_reference_t<value_type>;

	virtual void SetVal(int val) override
	{
		m_val = static_cast<int>(val);
		Callback(this);
	}

	virtual int GetVal() const override
	{
		return static_cast<int>(m_val);
	}

private:
	base_type m_val;
};

static void Callback2(IWidget* w)
{
	assert(w->GetVal() == 2);
}

// --- Approach 3 for functor & lambda --- //
// NOTE: We store CALLBACK as functor type as we allocate it on stack as data member of the class to call later.
// NOTE2: Functor needs to be passed as argument for function of template class, or do it like we did here passing functor's type
// then declare it as data member to be called later.
// NOTE3: type template parameter is the one that can work with both functor and function although the former must be passed with both its type as template argument, and instance of it as argument to template's function.
template <typename TYPE, typename CALLBACK>
class Widget3 : public IWidget
{
public:
	using value_type = TYPE;
	using base_type = std::remove_reference_t<value_type>;

	virtual void SetVal(int val) override
	{
		m_val = static_cast<int>(val);
		m_callback(this);
	}

	virtual int GetVal() const override
	{
		return static_cast<int>(m_val);
	}

	void Perform(CALLBACK* c)
	{
		(*c)(this);
	}
	
	// NOTE: use different function name to differentiate it from Perform()
	template <typename T>
	void PerformLD(T lambda)
	{
		lambda(this);
	}

private:
	base_type m_val;
	CALLBACK m_callback;
};

struct Callback3
{
	virtual void operator()(IWidget* w) const
	{
		assert(w->GetVal() == 3);
	}
};
struct Callback4 : public Callback3
{
	virtual void operator()(IWidget* w) const override
	{
		std::cout << "Callback4::operator()(IWidget* w)" << std::endl;
		assert(w->GetVal() == 3);
	}
};

int main()
{
	{
		Widget<int> w_empty;
		w_empty.SetVal(100);

		Widget<int, Callback1> w;
		w.SetVal(1);
	}
	{
		Widget2<int, Callback2> w;
		w.SetVal(2);
	}
	{
		Widget3<int, Callback3> w;
		w.SetVal(3);

		Callback4* c4 = new Callback4();
		w.Perform(c4);	
		w.PerformLD([](IWidget* w) {
			std::cout << "Called from lambda" << std::endl;
			assert(w->GetVal() == 3);
		});
	}
	return 0;
}
