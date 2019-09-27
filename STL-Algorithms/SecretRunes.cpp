/**
 * Demonstrate usage of STL Algorithms - Secret Runes
 * Includes
 *  - stable_*
 *      - std::stable_sort
 *      - std::stable_partition
 *  - is_*
 *      - std::is_sorted
 *      - std::is_partitioned
 *      - std::is_heap
 *  - is_*_until
 *      - std::is_sorted_until
 *      - std::is_partitioned_until (not available on g++ 9.0 Linux)
 *      - std::is_heap_until
 */

#include <iostream>
#include <vector>
#include <algorithm>

struct Widget
{
    int value;
    int pos;

    Widget(int value, int pos): value(value), pos(pos) { }
    int operator*() const { return value; }

    friend std::ostream& operator<< (std::ostream& os, const Widget& obj)
    {
        os << obj.value << "(" << obj.pos << ")";
        return os;
    }
};

// conveniently define a vector for input into use with STL algorithms
#define VINPUT std::vector<Widget> v = {Widget(2,0), Widget(1,1), Widget(20,2), Widget(1,3), Widget(1,4), Widget(1,5), Widget(1,6)};
#define VINPUT_SORTED std::vector<Widget> vs = {Widget(1,0), Widget(5,1), Widget(5,2), Widget(25,3), Widget(55,4), Widget(73,5), Widget(100,6), Widget(240,7)};
#define VINPUT_UNSORTED std::vector<Widget> vus = {Widget(100,0), Widget(5,1), Widget(73,2), Widget(25,3), Widget(240,4), Widget(5,5), Widget(1,6), Widget(55,7)};

template <typename Iter>
static void printElems(Iter begin, Iter end, const std::string prefix, bool newline=true)
{
    std::cout << prefix;
    for (auto it = begin; it != end; ++it)
    {
        std::cout << *it << " ";
    }
    if (newline)
        std::cout << std::endl;
}

int main()
{
    {
        VINPUT
        printElems(v.begin(), v.end(), "v => ");   

        VINPUT_UNSORTED
        printElems(vus.begin(), vus.end(), "v_unsorted => ");

        VINPUT_SORTED
        printElems(vs.begin(), vs.end(), "v_sorted => ");
    }

    std::cout << std::endl;

    // stable_*
    //  - std::stable_sort
    {
        // std::sort (for comparison)
        {
            VINPUT
            std::sort(v.begin(), v.end(), [](const Widget& a, const Widget& b) { return a.value < b.value; });
            // note: now notice the "pos:" value element with less pos value should be first, that's stable sorting
            // TODO: try to find the input case that produce the result with non-preserved position of element with same value
            printElems(v.begin(), v.end(), "std::sort (v) => ");
        }

        // std::stable_sort
        {
            VINPUT
            std::stable_sort(v.begin(), v.end(), [](const Widget& a, const Widget& b) { return a.value < b.value; });
            // note: now notice the "pos:" value element with less pos value should be first, that's stable sorting
            printElems(v.begin(), v.end(), "std::stable_sort (v) => ");
        }
    }

    // stable_*
    //  - std::stable_partition
    {
        VINPUT_UNSORTED
        // middle is the iterator pointing to the first of second group
        auto middle = std::stable_partition(vus.begin(), vus.end(), [](const Widget& obj){ return obj.value < 56; });
        printElems(vus.begin(), middle, "std::stable_partition (v_unsorted) => ", false);
        printElems(middle, vus.end(), "* ");
    }

    // is_*
    // std::is_sorted
    {
        auto comp = [](const Widget& a, const Widget& b){ return a.value < b.value; };

        VINPUT_SORTED
        std::cout << std::boolalpha << "std::is_sorted (v_sorted) => " << std::is_sorted(vs.begin(), vs.end(), comp) << std::endl;

        VINPUT_UNSORTED
        std::cout << std::boolalpha << "std::is_sorted (v_unsorted) => " << std::is_sorted(vus.begin(), vus.end(), comp) << std::endl;
    }

    // is_*
    // std::is_partitioned
    {
        auto comp = [](const Widget& obj) { return obj.value < 55; };

        VINPUT_UNSORTED
        std::cout << std::boolalpha << "std::is_partitioned (v_unsorted) => " << std::is_partitioned(vus.begin(), vus.end(), comp) << std::endl;       

        VINPUT_SORTED
        std::cout << std::boolalpha << "std::is_partitioned (v_sorted) => " << std::is_partitioned(vs.begin(), vs.end(), comp) << std::endl;       
    }

    // is_*
    // std::is_heap
    {
        auto comp = [](const Widget& a, const Widget& b) { return a.value < b.value; };

        VINPUT
        std::cout << std::boolalpha << "std::is_heap (v) => " << std::is_heap(v.begin(), v.end(), comp) << std::endl;

        std::make_heap(v.begin(), v.end(), comp);

        std::cout << std::boolalpha << "std::is_heap (v - after std::make_heap) => " << std::is_heap(v.begin(), v.end(), comp) << std::endl;
    }

    // is_*_until
    // std::is_sorted_until
    {
        auto comp = [](const Widget& a, const Widget& b) { return a.value < b.value; };

        VINPUT_SORTED
        auto it = std::is_sorted_until(vs.begin(), vs.end(), comp);

        if (it == vs.end())
            std::cout << "v_sorted is all sorted" << std::endl;
        else
            std::cout << "v_sorted is sorted until => " << (*it).value << " (index at " << std::distance(vs.begin(), it) << ")" << std::endl;

        VINPUT_UNSORTED
        it = std::is_sorted_until(vus.begin(), vus.end(), comp);

        if (it == vus.end())
            std::cout << "v_unsorted is all sorted" << std::endl;
        else
            std::cout << "v_unsorted is sorted until => " << (*it).value << " (index at " << std::distance(vus.begin(), it) << ")" << std::endl;
    }

    // is_*_until
    // std::is_partitioned_until
    // note: std::is_partitioned_until is not available on g++ 9.0 Linux.
    //{
    //    auto comp = [](const Widget& a, const Widget& b) { return a.value < b.value; };

    //    VINPUT_SORTED
    //    auto it = std::is_partitioned_until(vs.begin(), vs.end(), comp);

    //    if (it == vs.end())
    //        std::cout << "v_sorted is well partitioned" << std::endl;
    //    else
    //        std::cout << "v_sorted is partitioned until => " << (*it).value << " (index at " << std::distance(vs.begin(), it) << ")" << std::endl;

    //    VINPUT_UNSORTED
    //    it = std::is_partitioned_until(vus.begin(), vus.end(), comp);

    //    if (it == vus.end())
    //        std::cout << "v_unsorted is well partitioned" << std::endl;
    //    else
    //        std::cout << "v_unsorted is partitioned until => " << (*it).value << " (index at " << std::distance(vus.begin(), it) << ")" << std::endl;
    //}

    // is_*_until
    // std::is_heap_until
    {
        auto comp = [](const Widget& a, const Widget& b) { return a.value < b.value; };

        VINPUT_SORTED
        auto it = std::is_heap_until(vs.begin(), vs.end(), comp);

        if (it == vs.end())
            std::cout << "v_sorted is heap" << std::endl;
        else
            std::cout << "v_sorted is heap until => " << (*it).value << " (index at " << std::distance(vs.begin(), it) << ")" << std::endl;

        VINPUT_UNSORTED
        it = std::is_heap_until(vus.begin(), vus.end(), comp);

        if (it == vus.end())
            std::cout << "v_unsorted is heap" << std::endl;
        else
            std::cout << "v_unsorted is heap until => " << (*it).value << " (index at " << std::distance(vus.begin(), it) << ")" << std::endl;
    }

    return 0;
}
