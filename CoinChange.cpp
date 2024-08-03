/**
 * @file CoinChange.cpp
 * @brief Solution to the LeetCode problem "Coin Change"
 * @link https://leetcode.com/problems/coin-change/
 * 
 * Algorithm Explanation:
 * 
 * Problem Statement:
 * You are given coins of different denominations and a total amount of money amount. 
 * Write a function to compute the fewest number of coins that you need to make up that amount. 
 * If that amount of money cannot be made up by any combination of the coins, return -1.
 * 
 * To solve this problem, we can use dynamic programming. We can approach the problem in two ways: 
 * a recursive approach with memoization and an iterative approach.
 * 
 * Recursive Approach with Memoization:
 * 1. Define a helper function `helper(coins, amount)` that returns the minimum number of coins needed to make up the given amount.
 * 2. Base cases:
 *    - If `amount` is less than 0, return -1 (impossible to form the amount).
 *    - If `amount` is 0, return 0 (no coins are needed).
 * 3. Use a memoization array `dp` to store results of subproblems to avoid redundant calculations.
 * 4. If the result for `dp[amount]` is already computed, return `dp[amount]`.
 * 5. Iterate over each coin and recursively compute the minimum number of coins needed for `amount - coin`.
 * 6. Update `dp[amount]` with the minimum number of coins found.
 * 7. The final result for the minimum number of coins needed to make up `amount` is given by `helper(coins, amount)`.
 * 
 * Iterative Approach:
 * 1. Create a dynamic programming array `dp` of size `amount + 1` initialized to INT_MAX.
 * 2. Set `dp[0] = 0` (no coins are needed to make amount 0).
 * 3. For each amount from 1 to `amount`, compute the minimum number of coins needed.
 * 4. Iterate over each coin and update `dp[i]` with the minimum number of coins found.
 * 5. The final result for the minimum number of coins needed to make up `amount` is given by `dp[amount]`.
 * 
 * The iterative approach is used as the default method in our solution.
 */

#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

class Solution {
public:
    vector<int> dp;
    
    /**
     * @brief Helper function to compute the minimum number of coins needed to make up the amount recursively with memoization.
     * 
     * @param coins The vector of coin denominations.
     * @param amount The total amount of money.
     * @return int The minimum number of coins needed to make up the amount.
     */
    int helper(vector<int> &coins, int amount) {
        if (amount < 0) {
            return -1;
        }
        if (amount == 0) {
            return 0;
        }
        if (dp[amount] != INT_MIN) {
            return dp[amount];
        }
        
        int minSteps = INT_MAX;
        
        for (int coin : coins) {
            int steps = helper(coins, amount - coin);
            if (steps != -1) {
                minSteps = min(minSteps, steps + 1);
            }
        }
        
        dp[amount] = (minSteps == INT_MAX) ? -1 : minSteps;
        return dp[amount];
    }
    
    /**
     * @brief Computes the minimum number of coins needed to make up the amount using a recursive approach with memoization.
     * 
     * @param coins The vector of coin denominations.
     * @param amount The total amount of money.
     * @return int The minimum number of coins needed to make up the amount.
     */
    int recursive(vector<int> &coins, int amount) {
        dp.resize(amount + 1, INT_MIN);
        return helper(coins, amount);
    }
    
    /**
     * @brief Computes the minimum number of coins needed to make up the amount using an iterative approach with dynamic programming.
     * 
     * @param coins The vector of coin denominations.
     * @param amount The total amount of money.
     * @return int The minimum number of coins needed to make up the amount.
     */
    int iterative(vector<int> &coins, int amount) {
        dp.resize(amount + 1, INT_MAX);
        dp[0] = 0;
        
        for (int i = 1; i <= amount; i++) {
            for (int coin : coins) {
                if (coin <= i && dp[i - coin] != INT_MAX) {
                    dp[i] = min(dp[i], 1 + dp[i - coin]);
                }
            }
        }
        
        return dp[amount] == INT_MAX ? -1 : dp[amount];
    }
    
    /**
     * @brief Computes the minimum number of coins needed to make up the amount.
     * 
     * This function defaults to using the iterative approach.
     * 
     * @param coins The vector of coin denominations.
     * @param amount The total amount of money.
     * @return int The minimum number of coins needed to make up the amount.
     */
    int coinChange(vector<int>& coins, int amount) {
        return iterative(coins, amount);
        // return recursive(coins, amount);
    }
};

