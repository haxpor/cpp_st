/**
 * Demonstrate comparison of recursive and dynamic programming over Fibonacci Numbers solution.
 */

#include <iostream>
#include <vector>
#include <chrono>

static int FiboRecursive(const int n)
{
    if (n <= 1)
        return n;
    return FiboRecursive(n - 1) + FiboRecursive(n - 2);
}

static int FiboDP(const int n)
{
    std::vector<int> v;
    v.reserve(n);

    v[0] = 0;
    v[1] = 1;

    for (int i=2; i<=n; ++i)
    {
        v[i] = v[i-1] + v[i-2];
    }

    return v[n];
}

int main()
{
    auto t1 = std::chrono::high_resolution_clock::now();
    std::cout << "FiboRecursive(10) = " << FiboRecursive(10) << std::endl;
    std::cout << " elapsed in " << std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - t1).count() << " ms" << std::endl;

    t1 = std::chrono::high_resolution_clock::now();
    std::cout << "FiboDP(10) = " << FiboDP(10) << std::endl;
    std::cout << " elapsed in " << std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - t1).count() << " ms" << std::endl;
    return 0;
}
