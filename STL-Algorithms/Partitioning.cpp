/**
 * Demonstration of Partitioning STL Algorithms
 * Includes
 *  - std::partition
 *  - std::partition_point
 */

#include <iostream>
#include <vector>
#include <algorithm>

using cIter = std::vector<int>::const_iterator;
static void printElems(cIter start, cIter end)
{
    for (auto iter = start; iter!=end; ++iter)
    {
        std::cout << *iter << " ";
    }
}

int main()
{
    std::vector<int> v = {1, 15, 34, 120, 25, 12, 60};

    auto pred = [](const int& v)
    {
        return v % 5 == 0;
    };

    // use std::partition to split true & false case of predicate separated by resultant iterator
    auto middle = std::partition(v.begin(), v.end(), pred);
    std::cout << "std::partition: ";
    printElems(v.begin(), middle);
    std::cout << " * ";
    printElems(middle, v.end());
    std::cout << std::endl;

    // use std::partition_point to find such iterator that separates between true & false predicate
    middle = std::partition_point(v.begin(), v.end(), pred);
    std::cout << "parition point (iterator): " << *middle << std::endl;
    std::cout << "parition point (index): " << std::distance(v.begin(), middle) << std::endl;

    return 0;
}
