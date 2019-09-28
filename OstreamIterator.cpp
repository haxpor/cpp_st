/**
 * Demonstrate usage of std::ostream_iterator.
 * There are main 5 types of iterator, output iterator is just one of them thus std::ostream_iterator.
 *
 * Those 5 types are as follows
 *  1. Input iterator - program can use to read value from a container
 *  2. Output iterator - moving information from a program to a container
 *  3. Forward iterator - use only operator++ to go forward in the container
 *  4. Bidirectional iterator - can go in either direction
 *  5. Random access iterator - provide random access into container
 */

#include <iostream>
#include <iterator>

int main()
{
    // template accepts two types
    // 1. the type to write to ostream
    // 2. the ostream character type
    std::ostream_iterator<std::string, char> oIterator(std::cout, "\n");

    oIterator = "First line";

    // interesting note: operator++ and operator* is no-op
    // if peek into header source, it just return reference to itself via `return *this`
    *oIterator++ = "Second line";
    return 0;
}
