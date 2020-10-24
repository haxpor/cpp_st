/**
 * Ref: http://www.gotw.ca/gotw/030.htm
 */
#include <string>
#include <iostream>

namespace NS
{
    class T { };
    void f(T) { std::cout << "f(T)" << std::endl; };
};

NS::T param;

int main()
{
    // output would be 'f(T)'
    // as NS::T as argument to f(T) bring in namespace NS into consideration thus f(T) inside such
    // namespace is also brought into consideration as well
    f(param);
}
