/**
 * mySet will be formed with unique values inside parenthesis.
 */
#include <iostream>
#include <set>

int main() {
    std::set<int> mySet = {1,1,2,3};
    for (auto v : mySet) {
        std::cout << v << " ";
    }
    return 0;
}
