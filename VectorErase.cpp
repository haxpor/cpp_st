/**
 * Demonstrate the effect of erase() call for std::vector to validate whether it reduces the
 * physical size of the container or not.
 *
 * As per man page of std::vector::erase, it doesn't mention anything about physical size after
 * calling erase(). The direct function to have effect on this is shrink_to_fit() which might be
 * better to achieve that.
 */

#include <iostream>
#include <vector>

using namespace std;

int main()
{
    vector<int> v {1,2,3,4,5};

    // erase() doesn't reduce physical size down to match logical size
    // even though man page of std::vector::erase states that it will call destructor of such object
    // but it's only for stack type, not heap.
    v.erase(v.begin(), v.begin()+2);
    for (const int& i: v)
    {
        cout << i << endl;
    }

    cout << v.size() << " " << v.capacity() << endl;
    // call shrink_to_fit() to reduce physical size to match logical size
    v.shrink_to_fit();
    cout << v.size() << " " << v.capacity() << endl;
    return 0;
}
