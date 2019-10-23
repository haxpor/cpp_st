/**
 * Test prove of concept for the case shown in CppCon 2019: Jason Turner "The Best Parts of C++".
 * In which at 47:52 minutes mark, he presents with the following example code which has double free
 * problem in C++11 if you disable RVO via -fno-elide-constructors.
 *
 * As `data` is allocated, and itself is a pointer. Thus pointer is copied. So double free
 * can occur to deallocate the already allocated memory space.
 */
#include <iostream>
#include <cstddef>

struct Double_Data
{
    Double_Data(const std::size_t size) : data(new double[size])
    {
        std::cout << "Construct data: " << static_cast<void*>(data) << std::endl;
    }
    ~Double_Data()
    {
        std::cout << "Free data: " << static_cast<void*>(data) << std::endl;
        delete [] data;
    }
    double *data;
};

Double_Data get_data()
{
    Double_Data data(3);
    data.data[0] = 1.1;
    data.data[1] = 2.2;
    data.data[2] = 3.3;
    return data;
}

double sum_data(const Double_Data& d)
{
    return d.data[0] + d.data[1] + d.data[2];
}

int main()
{
    sum_data(get_data());
    return 0;
}
