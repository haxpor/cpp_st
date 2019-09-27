/**
 * Demonstrate usage of STL Algorithms - Permutations
 * Includes
 *  - std::rotate
 *  - std::shuffle
 *  - std::next_permutation
 *  - std::prev_permutation
 *  - std::reverse
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

// conveniently define a vector for input into use with STL algorithms
#define VINPUT std::vector<int> v = {50, 30, 1, 9, 120, 67, 42};

template <typename Iter>
static void printElems(Iter begin, Iter end, const std::string prefix)
{
    std::cout << prefix;
    for (auto it = begin; it != end; ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

int main()
{
    {
        VINPUT
        printElems(v.begin(), v.end(), "Input => ");   
    }

    // std::rotate
    {
        VINPUT

        // we can think of operation as swap, the n_first parameter will be swapped to be at the first element
        // and n_first - 1 will be at the end of the specified range
        // insertion sort can be done using std::rotate (with help of std::upper_bound) to implement such
        // algorithm.
        std::rotate(v.begin(), v.begin()+4, v.end());
        printElems(v.begin(), v.end(), "std::rotate => ");

        // if confused by the way rotating works, this might help http://www.cplusplus.com/reference/algorithm/rotate/
        std::rotate(v.begin(), v.begin()+3, v.end()-1);
        printElems(v.begin(), v.end(), "std::rotate (with  size-1) => ");
    }

    // std::shuffle
    {
        VINPUT
        // we need to create random generator to supply to std::shuffle
        // note: for interested personels for non-deterministic random number generators in C++ which
        // solely rely on hardware support, and cannot be created easily without one. We only get
        // deterministic pseudo-number generator (PRNG), and Mersenne Twister is probably the best to use
        // out there (even by default std::random_device uses it).
        std::random_device rd;
        std::mt19937 g(rd());
        std::cout << std::boolalpha << "Is random device non-deterministic => " << (rd.entropy() != 0) << std::endl;
        std::cout << "  entropy value via std::random_device::entropy() => " << rd.entropy() << std::endl;
        std::shuffle(v.begin(), v.end(), g);
        printElems(v.begin(), v.end(), "std::shuffle => ");
    }

    // std::next_permutation, std::prev_permutation and std::reverse
    // note: the input range needs to be sorted lexicographically first
    {
        std::string str = {"abca"};
        std::sort(str.begin(), str.end());
        printElems(str.begin(), str.end(), "sorted string => ");
        printElems(str.begin(), str.end(), "staring permutation => ");
        while (std::next_permutation(str.begin(), str.end()))
        {
            printElems(str.begin(), str.end(), "  std::next_permutation => ");
        }

        std::cout << std::endl;

        // reverse the input range, by now it's already back to original which is sorted
        // then we just reverse it preparing as input for std::prev_permutation
        std::reverse(str.begin(), str.end());
        printElems(str.begin(), str.end(), "staring permutation => ");
        while (std::prev_permutation(str.begin(), str.end()))
        {
            printElems(str.begin(), str.end(), "  std::prev_permutation => ");
        }
    }

    return 0;
}
