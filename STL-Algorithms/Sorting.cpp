/**
 * Demonstrate usage of sorting in <algorithm>
 * This includes
 *  - std::sort
 *  - std::partial_sort
 *  - std::sort_heap
 *  - std::nth_element
 *  - std::inplace_merge
 */

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

// conveniently define a vector for input into use with STL algorithms
#define VINPUT std::vector<int> v = {50, 30, 1, 9, 120, 67, 42};
// conveniently define a heap from vector
#define VHEAPINPUT std::vector<int> v = {50, 30, 1, 9, 120, 67, 42}; std::make_heap(v.begin(), v.end());

static void printElems(const std::vector<int>& v)
{
    for (const int& e: v)
    {
        std::cout << e << " ";
    }
    std::cout << std::endl;
}

using cIter = std::vector<int>::const_iterator;
static void printElems(cIter start, cIter end, std::string prefix)
{
    std::cout << prefix;
    for (auto it=start; it != end; ++it)
    {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
}

int main()
{
    // print all input elements
    {
        VINPUT
        std::cout << "Input => ";
        printElems(v);
    }
    // std::sort
    // it uses introsort to sort the range
    // introsort uses quicksort first, then when exceed a certain level of recursion depth then
    // switch to use heap sort
    {
        VINPUT
        std::sort(v.begin(), v.end());
        std::cout << "std::sort => ";
        printElems(v);
    }

    // std::partial_sort
    // it uses heap sort to sort the range
    {
        VINPUT
        int middle = v.size() / 2;
        std::partial_sort(v.begin(), v.begin() + middle, v.end());
        std::cout << "std::partial_sort (middle at index " << middle << ") => ";
        printElems(v);
    }

    // std::sort_heap
    // sort the max-heap range with heap sorting algorithm into an ascending order range; result is not
    // a heap representation anymore but it just uses heap's ability of sorting to help on this.
    // note: the input range need to be max-heap representation, use std::make_heap to help on this
    {
        VHEAPINPUT
        std::sort_heap(v.begin(), v.end());
        std::cout << "std::sort_heap => ";
        printElems(v);
    }

    // same effect as of std::sort_heap but done it manually by keep popping max-heap to get an ascending sorted range
    {
        VHEAPINPUT
        std::cout << "std::pop_heap (manual to achive std::sort_heap)\n";
        for (int i=0; i<v.size()-1; ++i)
        {
            std::cout << "  std::pop_heap (step " << (i+1) << ") => ";
            std::pop_heap(v.begin(), v.end()-i);
            printElems(v);
        }
    }

    // std::nth_element
    // it only partially sort the range until the target nth element we want, if it's end() of the range
    // then there is no effect.
    {
        VINPUT
        std::cout << "std::nth_element (nth is 2nd element)\n";
        auto it = v.begin() + 1;    // such element is 30
        std::cout << "  nth (before) => " << *it << std::endl;
        std::nth_element(v.begin(), it, v.end());
        std::cout << "  nth (after) => " << *it << std::endl;
        std::cout << "  std::nth_element => ";
        printElems(v);
    }

    // std::inplace_merge
    // it is an incremental step in merge sort, even example of man page of std::inplace_merge also
    // demonstrates using it in incremental step of merge sort implementation
    {
        using Iter = std::vector<int>::iterator;

        // defining recursive lambda function is chicken-egg problem
        // so use std::function to have it defined and used inside the lambda itself.
        // note: we can assign lambda function to std::function, it will create std::function from
        // input lambda function internally.
        std::function<void(Iter, Iter)> merge_sort;
        merge_sort = [&merge_sort](Iter start, Iter end) -> void
        {
            if (end - start > 1)
            {
                Iter middle = start + (end - start)/2;

                // notice middle, here the range is [start, middle), and [middle, end).
                // thus we don't have to +1 for 2nd range for middle
                merge_sort(start, middle);
                merge_sort(middle, end);

                printElems(start, middle, "  1st half: ");
                printElems(middle, end, "  2nd half: ");

                std::inplace_merge(start, middle, end);

                std::cout << std::endl;
            }
        };

        VINPUT
        std::cout << "std::inplace_merge (as part of mergesort)\n";
        merge_sort(v.begin(), v.end());
        std::cout << "  Result => ";
        printElems(v);
    }

    return 0;
}
