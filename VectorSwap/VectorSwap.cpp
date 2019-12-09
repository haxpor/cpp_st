/**
 * Validate swapping efficiently between two std::vector
 */
#include <iostream>
#include <vector>
#include <chrono>

struct Profile
{
    static std::chrono::steady_clock::time_point gProfile_startTime;

    inline static void Start()
    {
        gProfile_startTime = std::chrono::steady_clock::now();
    }

    inline static void EndAndPrint()
    {
        std::cout << " execution elapsed " << std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - gProfile_startTime).count() << "ms" << std::endl;
    }

    // std::chrono::microseconds has type long int on 64-bit Linux (Ubuntu 18.04)
    // return in microseconds integer
    inline static long int End()
    {
        return std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::steady_clock::now() - gProfile_startTime).count();
    }
};

std::chrono::steady_clock::time_point Profile::gProfile_startTime;

void PrintAll(const std::vector<int>& v)
{
    for (const auto& e : v)
    {
        std::cout << e << ' ';
    }
    std::cout << std::endl;
}

void Add1M(std::vector<int>& v, bool reverse=false)
{
    if (reverse)
    {
        for (int i=1e+8; i>=0; --i)
        {
            v.emplace_back(i);
        }
    }
    else
    {
        for (int i=1; i<=1e+8; ++i)
        {
            v.emplace_back(i);
        }
    }
}

int main()
{
    std::vector<int> v1;
    std::vector<int> v2;

    Add1M(v1);
    Add1M(v2, true);

    long int elapsed;
    // std::swap
    Profile::Start();
    std::swap(v1, v2);
    elapsed = Profile::End();
    std::cout << "via std::swap : " << elapsed << "ms\n";

    // std::vector::swap
    Profile::Start();
    v1.swap(v2);
    elapsed = Profile::End();
    std::cout << "via std::vector::swap : " << elapsed << "ms\n";
    
    return 0;
}
