/**
 * Studying how to implement C# property in C++.
 * As seen from https://www.codeguru.com/cpp/cpp/cpp_mfc/article.php/c4031/Implementing-a-Property-in-C.htm
 *
 * Slightly modified from the original solution
 *  - function pointer for getter points to const function (note `const` at the end)
 */

#include <iostream>
#include <cassert>

#define READ_ONLY 1
#define WRITE_ONLY 2
#define READ_WRITE 3

/// Property
/// Template class used as utility to achieve property as used in C# in C++
template <typename Container, typename ValueType, int nPropType>
class Property
{
public:
    Property()
    {
        m_cObject = nullptr;
        Set = nullptr;
        Get = nullptr;
    }

    void setContainer(Container* cObject)
    {
        m_cObject = cObject;
    }

    void setter(void (Container::*pSet)(ValueType value))
    {
        if ((nPropType == WRITE_ONLY) || (nPropType == READ_WRITE))
            Set = pSet;
        else
            Set = nullptr;
    }

    void getter(ValueType (Container::*pGet)() const)
    {
        if ((nPropType == READ_ONLY) || (nPropType == READ_WRITE))
            Get = pGet;
        else
            Get = nullptr;
    }

    ValueType operator=(const ValueType& value)
    {
        assert(m_cObject != nullptr);
        assert(Set != nullptr);
        (m_cObject->*Set)(value);
        return value;
    }

    /// conversion operator
    /// define the conversion operator function so we can call getter member function of Container
    operator ValueType()
    {
        assert(m_cObject != nullptr);
        assert(Get != nullptr);
        return (m_cObject->*Get)();
    }

private:
    Container* m_cObject;                               // pointer to module that contains the getter/setter function
    void (Container::*Set)(ValueType value);            // pointer to member setter function of Container type
    ValueType (Container::*Get)() const;                // pointer to member getter function of Container type
};

/// Consumer class of Property
class Widget
{
public:
    Widget(): m_nCount(0)
            , m_nFloat(0.0f)
    {
        Count.setContainer(this);
        Count.setter(&Widget::setCount);
        Count.getter(&Widget::getCount);

        Float.setContainer(this);
        Float.setter(&Widget::setFloat);
        Float.getter(&Widget::getFloat);
    }

    /// -- getter/setter for m_nCount --
    int getCount() const
    {
        return m_nCount;
    }

    void setCount(int nCount)
    {
        m_nCount = nCount;
    }
    Property<Widget, int, READ_WRITE> Count;
    /// -- end of getter/setter section for m_nCount --
    
    /// -- getter/setter for m_nFloat --
    float getFloat() const
    {
        return m_nFloat;
    }

    void setFloat(float nFloat)
    {
        m_nFloat = nFloat;
    }
    Property<Widget, float, READ_WRITE> Float;
    /// -- end of getter/setter for m_nFloat --

private:
    int m_nCount;
    float m_nFloat;
};

int main()
{
    Widget w;
    std::cout << "Count\n";
    std::cout << "before: " << w.Count << '\n';
    w.Count = 1;                                    // setter usage
    std::cout << "after: " << w.Count << '\n';      // getter usage

    std::cout << "Float\n";
    std::cout << "before: " << w.Float << '\n';     // setter usage
    w.Float = 10.5f;
    std::cout << "after: " << w.Float << '\n';      // getter usage
    return 0;
}
