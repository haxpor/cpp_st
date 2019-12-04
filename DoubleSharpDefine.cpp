/**
 * Inspired via the following code as seen in CryEngine
 *
 *    #define DECLARE_SHARED_POINTERS(name)                   \
 *       typedef std::shared_ptr<name> name ##       Ptr;      \
 *       typedef std::shared_ptr<const name> name ## ConstPtr; \
 *       typedef std::weak_ptr<name> name ##         WeakPtr;  \
 *       typedef std::weak_ptr<const name> name ##   ConstWeakPtr;
 *
 *  Notice usage of ##
 */

#include <iostream>

#define DECLARE_TYPE(name) \
    typedef std::string name ## Type;

#define DECLARE_TYPE2(name) \
    typedef std::string name ## Type;

DECLARE_TYPE(MyString)
DECLARE_TYPE2(MyString2)

int main()
{
    MyStringType str = "My string";
    std::cout << str << std::endl;

    MyString2Type str2 = "My string2";
    std::cout << str2 << std::endl;
    return 0;
}
