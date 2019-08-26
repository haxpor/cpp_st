/**
 * Demonstrate using std::set in general.
 */

#include <iostream>
#include <set>

int main()
{
    // initialization
    // - via normal
    std::set<int> s1;
    s1.emplace(50);
    s1.emplace(75);
    s1.emplace(1);
    s1.emplace(1);  // doesn't allow duplicate key, but it's ok to still adding it

    // - via range-based initialization
    int ints[] = {1,2,4,5,6,80,120};
    std::set<int> s2(ints, ints+(sizeof(ints)/sizeof(int)));
    
    // general info query
    std::cout << "s1 size: " << s1.size() << "\n";
    std::cout << "s2 size: " << s2.size() << "\n";

    std::cout << "s1 max_size: " << s1.max_size() << "\n";
    std::cout << "s2 max_size: " << s2.max_size() << "\n";
    
    // lookup
    std::cout << "s1 matching 1: " << s1.count(1) << std::endl;
    std::cout << "s2 matching 1: " << s2.count(1) << std::endl;
    
    // data modification
    s1.erase(s1.begin());        // this removes one of 1 as it's sorted container
    s1.erase(s1.begin(), s1.find(75));     // this removes another 1 and 50
    for (const auto& e : s1)
    {
        std::cout << e << " ";
    }
    std::cout << std::endl;

    s1.erase(s2.find(6), s2.end()); // remove from 6 to the end
    for (const auto& e : s2)
    {
        std::cout << e << " ";
    }
    
    return 0;
}
