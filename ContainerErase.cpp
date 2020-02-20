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
int main() {
    std::unordered_multimap<int, int> map {{1,1}, {1,2}, {1,3}, {2,1}};
    auto it = map.begin();
    std::advance(it, 1);
    map.erase(map.begin(), it);     // erase the range from container
    std::cout << map.size() << '\n';

    map.erase(map.begin(), map.end());  // erase all elements
    std::cout << map.size() << '\n';
    return 0;
}
