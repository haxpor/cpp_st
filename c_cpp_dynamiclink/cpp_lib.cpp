#include "cpp_lib.h"
#include <numeric>
#include <vector>

/* make it overly complicated to make it require C++ standard library */
int sum_numbers(int a, int b)
{
    std::vector<int> tmpArray = {a, b};
    return std::accumulate(tmpArray.begin(), tmpArray.end(), 0);
}
