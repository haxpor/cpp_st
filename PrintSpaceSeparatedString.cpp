/**
 * Demonstrate how to print a space separated string in one line.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>

int main()
{
    std::vector<int> v {1,2,3,4,5,6};

    // note that there is trailing space as well
    std::copy(v.begin(), v.end(), std::ostream_iterator<int>(std::cout, " "));

    return 0;
}
