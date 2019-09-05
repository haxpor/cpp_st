/**
 * Demonstrate usage of STL Algorithms.
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

static void PrintElements(const std::vector<int>& v)
{
    std::cout << "Element of std::vector (" << std::addressof(v) << ")" << std::endl;
    for (auto i = v.begin(); i != v.end(); ++i)
    {
        std::cout << *i << " ";
    }
    std::cout << std::endl;
}

class EvenPredicate
{
public:
    template <typename T>
    bool operator() (const T& a)
    {
        return (a % 2) == 0;
    }
};
static EvenPredicate evenPred;

int main()
{
    std::vector<int> v1 { 1, 2, 3, 4, 90, 4, 5};
    std::vector<int> v2;
    // initialize 0 as element value
    // to let v2 has the same elements count as v1 for std::copy later
    for (int i=0; i<v1.size(); ++i)
    {
        v2.emplace_back(0);
    }

    // 1. std::copy
    // it needs destination container to have enough room (not empty) to copy
    // this is reason why we insert new initial element value before we do this
    // anyway, we can use std::back_inserter() to solve this problem to insert new element even
    // though we don't have enough or exact space to copy to at the destination side, see 8.
    std::copy(v1.begin(), v1.end(), v2.begin());   

    PrintElements(v1);
    PrintElements(v2);

    // 2. std::find
    // with using std::distance() to find the index location of such found iterator
    // this will find the first occurrence of 4
    auto findIter = std::find(v1.begin(), v1.end(), 4);
    if (findIter != v1.end())
    {
        std::cout << "Found 4! [" << *findIter << "] at " << std::distance(v1.begin(), findIter) << std::endl;
    }

    findIter = std::find(v1.begin(), v1.end(), 8);
    if (findIter == v1.end())
    {
        std::cout << "Not found" << std::endl;
    }

    // 3. std::find_if with functor
    findIter = std::find_if(v1.begin(), v1.end(), evenPred);
    if (findIter != v1.end())
    {
        std::cout << *findIter << std::endl;
    }

    // 3.1 std::find_if with lambda function
    findIter = std::find_if(v1.begin(), v1.end(), [](const int& x) { return (x % 2) == 0 && x != 2; });
    if (findIter != v1.end())
    {
        std::cout << *findIter << std::endl;
    }

    // 4. std::count
    // this is to find number of occurrences of value inside a container
    size_t count = std::count(v2.begin(), v2.end(), 4);
    std::cout << "4 occurs for " << count << " times" << std::endl;
    count = std::count(v2.begin(), v2.end(), 2);
    std::cout << "2 occurs for " << count << " times" << std::endl;

    // 4.1 std::count_if with functor
    count = std::count_if(v2.begin(), v2.end(), evenPred);
    std::cout << "Even number occurs " << count << std::endl;

    // 4.2 std::count_if with lambda function
    count = std::count_if(v2.begin(), v2.end(), [](const int& x) { return (x % 2) == 0;});
    std::cout << "Even number occurs " << count << std::endl;

    // 5. std::max_element
    auto maxIter = std::max_element(v2.begin(), v2.end());
    std::cout << "Max element: " << *maxIter << std::endl;
    
    // 6. std::min_element
    auto minIter = std::min_element(v2.begin(), v2.end());
    std::cout << "Min element: " << *minIter << std::endl;

    // 7. std::accumulate
    auto sum = std::accumulate(v2.begin(), v2.end(), 10);
    std::cout << "Sum with initial 10: " << sum << std::endl;

    sum = std::accumulate(v2.begin(), v2.end(), 10, [](const int& a, const int& b) { return a + b + 10; });
    std::cout << "Sum with initial 10 (+10 each time): " << sum << std::endl;
    
    // 8. std::back_inserter
    std::vector<int> v3;
    std::copy(v1.begin(), v1.end(), std::back_inserter(v3));
    for (auto i=v3.begin(); i != v3.end(); ++i)
    {
        std::cout << *i << " ";
    }
    std::cout << std::endl;

    // 9. std::remove_copy_if
    std::vector<int> v4;
    std::remove_copy_if(v3.begin(), v3.end(), std::back_inserter(v4), [](const int& x) { return x == 2; });
    for (auto const& e : v4)
    {
        std::cout << e << " ";
    }
    std::cout << std::endl;

    // 10. std::sort
    std::sort(v4.begin(), v4.end());
    for (auto const& e : v4)
    {
        std::cout << e << " ";
    }
    std::cout << std::endl;

    return 0;
}
