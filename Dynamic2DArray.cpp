/**
 * Demonstrate how to declare 2d array dynamically/
 *
 * Basically dynamic 2d array is array of pointers to array.
 * Mostly use this to solve the issue of VLA (Variable Length Array). Think about the case of
 * accepting input of size of something from input, then use it to define array. We can directly use
 * such value but it has side-effect of overflow the stack size. Take warning from compiler very carefully.
 *
 * Thus define it dynamically will solve the compiler's warning.
 * 
 * Read more about VLA at https://www.reidatcheson.com/c/programming/2015/12/07/vlas.html.
 */

#include <iostream>
#include <cstdlib>

using namespace std;

struct Data
{
    int n;

    Data(): n(0) { cout << "ctor" << endl; }
    Data(int n): n(n) { cout << "ctor" << endl; }
    ~Data() { cout << "dtor" << endl; }
};

int main(int argc, char* argv[])
{
    if (argc < 3)
    {
        cerr << "Not enough argument\n" << "Usage: ./a.out M N\n" << "wheres M and N are any positive integer number" << endl;
        return 1;
    }

    int m = atoi(argv[1]);
    int n = atoi(argv[2]);

    int val = 1;

    // allocate array of pointers of size m
    Data** ptr = new Data*[m];

    // for each row, allocate an array of size n
    for (int i=0; i<m; ++i)
    {
        ptr[i] = new Data[n];
    }

    // initialize values for each element
    for (int i=0; i<m; ++i)
    {
        for (int j=0; j<n; ++j)
        {
            ptr[i][j].n = val++;
            cout << ptr[i][j].n << " ";
        }
        cout << endl;
    }

    // clean up memory
    // firstly clean up array for each row
    for (int i=0; i<m; ++i)
    {
        delete[] ptr[i];
    }
    // clean up all rows
    delete ptr;

    return 0;
}
