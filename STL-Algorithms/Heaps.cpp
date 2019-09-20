/**
 * Demonstate usage of heaps algorithm
 *
 * This is as part of Province of Heaps.
 * This include the following list.
 *  - std::make_heap
 *  - std::push_heap
 *  - std::pop_heap
 */

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define PRINTALL(v) for (const int& e: v) cout << e << " "; cout << endl;

int main()
{
    vector<int> v {3, 2, 4, 1, 5, 9};
    PRINTALL(v)
    make_heap(v.begin(), v.end());
    PRINTALL(v)

    // push a new element into vector
    v.emplace_back(13);

    cout << "before std::push_heap\n";
    PRINTALL(v)

    cout << "after std::push_heap\n";
    push_heap(v.begin(), v.end());
    PRINTALL(v)

    // erase an element in vector
    // std::pop_heap expect external operation to pop element from the first location out
    // if you erase at arbitrary location, then call std::pop_heap, then result is wrong
    // in short, we need to adhere to the operation of heap data structure, do something with front element only
    v.erase(v.begin());
    cout << "before std::pop_heap\n";
    PRINTALL(v)

    cout << "after std::pop_heap\n";
    pop_heap(v.begin(), v.end());
    PRINTALL(v)

    // iteratively sort the heap in ascending order
    // provided that we don't pop_back() when we do pop_heap()
    // note: finally we will see a sorted heap when it processes through all of element
    int iend=0;
    const int iendEnd = distance(v.begin(), v.end()-1);
    while (iend<iendEnd)
    {
        pop_heap(v.begin(), v.end()-iend);
        PRINTALL(v)
        ++iend;
    }

    return 0;
}
