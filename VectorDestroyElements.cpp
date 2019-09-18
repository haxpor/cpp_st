/**
 * Demonstrate how to destroy elements inside std::vector<*Ptr> with its erase() and manually by
 * hands via delete operator.
 */
#include <iostream>
#include <vector>

using namespace std;

struct Data
{
    Data() { cout << "ctor" << endl; }
    ~Data() { cout << "dtor" << endl; }
};

int main()
{
    {
        cout << "Case 1" << endl;

        // case 1: Elements removed by pop_back() are not destroyed, you won't see "dtor" printed
        //         out on console
        vector<Data*> v;
        Data* d1 = new Data();
        Data* d2 = new Data();
        v.push_back(d1);
        v.push_back(d2);

        while (!v.empty())
        {
            v.pop_back();
        }

        // we won't see any "dtor" up to this point
        
        // to really destroy elements, we can do it manually via delete operator
        delete d1;
        delete d2;
    }

    cout << endl;

    {
        cout << "Case 2" << endl;
        
        // case 2: Pointer elements are still NOT affected by a call to erase(), man page states
        //         that it call destructor of type T but it applies only when it's stack type.
        //         Pointer type needs user to handle manually via delete operator.
        vector<Data*> v ({ new Data(), new Data() });
        v.erase(v.begin(), v.end());

        // you won't see any dtor up to this point.

        // prove that for pointer type, you need to handle manually
    }

    cout << endl;

    {
        cout << "Case 3" << endl;

        // case 3: Demonstrate manually delete all elements by hands, then make vector's state consistent
        //         by calling clear() at the end.
        vector<Data*> v ({ new Data(), new Data() });
        for (int i=0; i<v.size(); ++i)
        {
            delete v[i];
        }

        // size is still 2 at this point although we delete all pointer elements
        cout << v.size() << endl;

        // clear all elements to make its state consistent
        v.clear();

        cout << v.size() << endl;
    }
    return 0;
}
