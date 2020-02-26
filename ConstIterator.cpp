/**
 * Notice that const_iterator is okay to be used in iterating element by element via ++it.
 * It just means we are not going to modify element value, but not iterator's state itself.
 * const_iterator points to `const T*` when we dereference it to get `const T&`.
 *
 * Using const_iterator is likely to provide better performance as there would be copying necessary (related
 * to COW - copy-on-write), and with hints to compiler to do optimization further on const data.
 */
#include <iostream>
#include <list>

int main() {
    std::list<int> l {1,2,3,4,5};
    for (std::list<int>::const_iterator it=l.begin(); it!=l.end(); ++it) {
        std::cout << *it << ' ';
    }
    return 0;
}
