/**
 * Test case for usage of erase() function of container.
 * The ending range is past-the-end.
 *
 * This source tests usage of the following
 *  - container's erase() function. Note its ending iterator which is past-the-end.
 *  - std::advance() to advance iterator
 */
#include <unordered_map>
#include <iostream>
#include <cassert>

int main() {
    {
        std::unordered_multimap<int, int> map {{1,1}, {1,2}, {1,3}, {2,1}};
        auto it = map.begin();
        std::advance(it, 1);
        map.erase(map.begin(), it);     // erase the range from container
        assert(map.size() == 3);

        map.erase(map.begin(), map.end());  // erase all elements
        assert(map.size() == 0);
    }

    {
        // This is the incorrect use of erase() which intends to remove all elements resulting from
        // equal_range(). Result cannot be used in erase() to remove all such elements from the container.
        //std::unordered_multimap<int, int> map {{1,1}, {1,2}, {2,1}, {1,3}, {2,2}};
        //auto range = map.equal_range(1);
        //map.erase(range.first, range.second);
        //assert(map.size() == 2);
    }
    return 0;
}
