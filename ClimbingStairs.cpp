/**
 * @file ClimbingStairs.cpp
 * @brief Solution to the LeetCode problem "Climbing Stairs"
 * @link https://leetcode.com/problems/climbing-stairs/
 * 
 * Algorithm Explanation:
 * 
 * Problem Statement:
 * You are climbing a staircase. It takes `n` steps to reach the top. Each time you can either climb 1 or 2 steps.
 * In how many distinct ways can you climb to the top?
 * 
 * To solve this problem, we can use dynamic programming. We can approach the problem in two ways: 
 * a recursive approach with memoization and an iterative approach.
 * 
 * Recursive Approach with Memoization:
 * 1. Define a helper function `helper(n)` that returns the number of ways to reach the nth step.
 * 2. Base cases:
 *    - If `n` is less than 3, return `n` (since there are `n` ways to climb `n` steps when `n` is 1 or 2).
 * 3. Use a memoization array `dp` to store results of subproblems to avoid redundant calculations.
 * 4. If the result for `dp[n]` is already computed, return `dp[n]`.
 * 5. Otherwise, compute `dp[n]` as the sum of `helper(n - 1)` and `helper(n - 2)` and store the result in `dp[n]`.
 * 6. The final result for the number of ways to reach `n` steps is given by `helper(n)`.
 * 
 * Iterative Approach:
 * 1. Create a dynamic programming array `dp` of size `n + 1` initialized to 0.
 * 2. Initialize the base cases:
 *    - For `i = 1` to `min(n, 3)`, set `dp[i] = i` (since there are `i` ways to climb `i` steps).
 * 3. For each step from 4 to `n`, compute `dp[i]` as the sum of `dp[i - 1]` and `dp[i - 2]` (since you can reach the ith step from either the (i-1)th or the (i-2)th step).
 * 4. The final result for the number of ways to reach `n` steps is given by `dp[n]`.
 * 
 * The iterative approach is used as the default method in our solution.
 */

#include <vector>

using namespace std;

class Solution {
public:
    vector<int> dp;
    
    /**
     * @brief Helper function to compute the number of ways to climb stairs recursively with memoization.
     * 
     * @param n The number of stairs.
     * @return int The number of ways to climb to the nth stair.
     */
    int helper(int n) {
        if (n < 3) {
            return n;
        }
        if (dp[n] != -1) {
            return dp[n];
        }
        
        dp[n] = helper(n - 1) + helper(n - 2);
        return dp[n];
    }
    
    /**
     * @brief Computes the number of ways to climb stairs using a recursive approach with memoization.
     * 
     * @param n The number of stairs.
     * @return int The number of ways to climb to the nth stair.
     */
    int recursive(int n) {
        dp.resize(n + 1, -1);
        return helper(n);
    }
    
    /**
     * @brief Computes the number of ways to climb stairs using an iterative approach with dynamic programming.
     * 
     * @param n The number of stairs.
     * @return int The number of ways to climb to the nth stair.
     */
    int iterative(int n) {
        dp.resize(n + 1, 0);
        
        for (int i = 1; i <= min(n, 3); i++) {
            dp[i] = i;
        }
        
        for (int i = 4; i <= n; i++) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        
        return dp[n];
    }
    
    /**
     * @brief Computes the number of ways to climb stairs.
     * 
     * This function defaults to using the iterative approach.
     * 
     * @param n The number of stairs.
     * @return int The number of ways to climb to the nth stair.
     */
    int climbStairs(int n) {
        return iterative(n);
    }
};

