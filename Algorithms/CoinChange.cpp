/**
 * Demonstrate how to do recursive, and dynamic programming.
 * Solution for coin change problem.
 */

#include <iostream>
#include <chrono>

#define ARRAY_COUNT(arr, type) sizeof(arr)/sizeof(type)

// to use the following 2 macros, you need to declare
// std::chrono::high_resolution_clock::time_point startTime
// before using
#define PROFILE_START startTime = std::chrono::high_resolution_clock::now();
#define PROFILE_END std::cout << " execution elapsed " << std::chrono::duration_cast<std::chrono::microseconds>(std::chrono::high_resolution_clock::now() - startTime).count() << std::endl;

/**
 * Count the solutions of the following cases
 * 1. When coins[m-1] presents
 * 2. When coins[m-1] doesn't present
 *
 * Complexity of recursive function is O(m ^ 2) ; as both sub-functions inside the implementation
 * needs to call m times to reach the solution. Also it computes duplicated (already computed) solution
 * along the way.
 *
 * \param coins Array of coins
 * \param m Number of coins
 * \param n The target value to do coin change
 *
 * \return The number of solutions.
 */
static int coinCount_recur(int coins[], int m, int n)
{
    // n is 0 then there is 1 solution
    if (n == 0)
        return 1;

    // if n less than 0 then there is no solution
    if (n < 0)
        return 0;

    // if there is no coins left, but n is still left
    // then there is no solution
    if (m <= 0 && n >= 1)
        return 0;

    // more explanation for this line as follows
    // left side of + => count of solution included coins[m-1]
    // right side of + => count of solution excluded coins[m-1]
    //  we continue working on the recursive call (notice m is still the same, but target value deducted from previous iteration)
    return coinCount_recur(coins, m-1, n) + coinCount_recur(coins, m, n-coins[m-1]);
}

/**
 * The complexity of dynamic programming version is O(m * n).
 * We also able to avoid compute duplicated solutions, but just get it from the cache table.
 */
static int coinCount_DP(int coins[], int m, int n)
{
    // solutions also include the case that the target is zero as well
    // thus we define n+1 rows for our table
    int memo[n+1][m];
    
    // initialize only the first row to have 1 as solution as the target is zero
    // we will work from bottom up (but table as shown in code here is top down)
    for (int i=0; i<m; ++i)
        memo[0][i] = 1;

    for (int i=1; i<n+1; ++i)
    {
        for (int j=0; j<m; ++j)
        {
            // count of solution included coins[j]
            int c1 = (i-coins[j] >= 0) ? memo[i - coins[j]][j] : 0;
    
            // count of solution excluded coins[j]
            int c2 = (j >= 1) ? memo[i][j-1] : 0;

            memo[i][j] = c1 + c2;
        }
    }
    
    // we have worked from the bottom up to this point using the previous calculated values
    // to come up with new values higher up, thus the solution is at the last row & column
    return memo[n][m-1];
}

int main()
{
    int coins[] = {1, 2, 3};
    const int kSize = ARRAY_COUNT(coins, int);
    std::chrono::high_resolution_clock::time_point startTime;

    // -- recursive version -- //
    PROFILE_START
    std::cout << "Coin cout (recursive) with n=4 : " << coinCount_recur(coins, kSize, 4) << std::endl;
    PROFILE_END

    PROFILE_START
    std::cout << "Coin cout (recursive) with n=10 : " << coinCount_recur(coins, kSize, 10) << std::endl;
    PROFILE_END

    std::cout << std::endl;

    // -- dynamic programming version -- //
    PROFILE_START
    std::cout << "Coin count (DP) with n=4 : " << coinCount_DP(coins, kSize, 4) << std::endl;
    PROFILE_END

    PROFILE_START
    std::cout << "Coin count (DP) with n=10 : " << coinCount_DP(coins, kSize, 10) << std::endl;
    PROFILE_END

    return 0;
}
