/**
 * Companion comparison to SIMD SSE/SSE2 enabled of FindMaxSIMD.cpp.
 *
 * Execute with
 *  ./a.out < dataset.txt
 */
#include <iostream>
#include <vector>

int main()
{
    // turn off synchronize to c-stream, this can improve performance
    std::ios_base::sync_with_stdio(false);

    std::vector<float> nums;
    nums.reserve(1000000);

    int n;
    std::cin >> n;

    for (int i=0; i<n; ++i)
    {
        std::cin >> nums[i];
    }

    float max = nums[0];
    for (int i=1; i<n; ++i)
    {
        if (max < nums[i])
            max = nums[i];
    }

    std::cout << std::fixed << max << '\n';
    std::cout.flush();
    return 0;
}
