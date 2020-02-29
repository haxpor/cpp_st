/**
 * Sort std::pair based on first element, first before second element.
 * If first element in a is less than b, then sort in ascending order first.
 * But if it's equal then sort on the second element.
 *
 * This is simplified in just one line.
 */
#include <algorithm>
#include <iostream>
#include <tuple>
#include <utility>
#include <vector>

typedef std::pair<int, int> MyPair;

struct DoublePredicate {
    bool operator()(const MyPair& a, const MyPair& b) {
        // this line means if a.first < b.first then sort it base on that first
        // but if both of them equal then sort on second
        return a.first < b.first || (a.first == b.first && a.second < b.second);
    }
};

int main() {
    std::vector<MyPair> v {std::make_pair(3,1), std::make_pair(1,2), std::make_pair(2,3), std::make_pair(2,1), std::make_pair(1,1)};
    std::sort(v.begin(), v.end(), DoublePredicate());
    for (const auto& e : v) {
        std::cout << e.first << "," << e.second << '\n';
    }
    return 0;
}
