/**
 * @file CombinationSumIV.cpp
 * @brief Solution to the LeetCode problem "Combination Sum IV"
 * @link https://leetcode.com/problems/combination-sum-iv/
 * 
 * Algorithm Explanation:
 * 
 * Problem Statement:
 * Given an array of distinct integers nums and a target integer target, return the number of possible 
 * combinations that add up to target. The order of the numbers in the combination matters.
 * 
 * Approach:
 * - We can solve this problem using dynamic programming.
 * - We have two approaches: recursive with memoization and iterative.
 * 
 * Detailed Steps:
 * 1. **Recursive Approach with Memoization**:
 *    - Define a helper function `helper(cSum)` that returns the number of ways to achieve the sum `cSum` using the numbers in `nums`.
 *    - Base cases:
 *      - If `cSum` is less than 0, return 0.
 *      - If `cSum` is 0, return 1.
 *    - Use a memoization array `dp` to store the results of subproblems.
 *    - If the result for `dp[cSum]` is already computed, return `dp[cSum]`.
 *    - For each number in `nums`, recursively compute the number of ways to achieve the sum `cSum - num`.
 *    - Sum up the results for all numbers in `nums` to get the total number of ways to achieve `cSum`.
 * 
 * 2. **Iterative Approach**:
 *    - Create a DP array `dp` of size `target + 1` initialized to 0.
 *    - Set `dp[0] = 1` as there is one way to achieve the sum 0 (using no numbers).
 *    - Iterate over each sum from 1 to `target`.
 *    - For each number in `nums`, if it is less than or equal to the current sum, add the number of ways to achieve the sum `i - num` to `dp[i]`.
 *    - The final result is stored in `dp[target]`.
 * 
 * Time Complexity:
 * - O(n * target), where n is the size of `nums` and target is the target sum.
 * 
 * Space Complexity:
 * - O(target), for storing the memoization or DP array.
 */

#include <vector>
using namespace std;

class Solution {
public:
    vector<int> nums;
    vector<int> dp;
    
    /**
     * @brief Helper function to compute the number of combinations to achieve the sum `cSum` using recursive approach with memoization.
     * 
     * @param cSum The current sum to achieve
     * @return int The number of combinations to achieve the sum `cSum`
     */
    int helper(int cSum) {
        if (cSum < 0) {
            return 0;
        }
        if (cSum == 0) {
            return 1;
        }
        if (dp[cSum] != -1) {
            return dp[cSum];
        }
        
        int numWays = 0;
        
        for (int i = 0; i < nums.size(); i++) {
            numWays += helper(cSum - nums[i]);
        }
        
        return dp[cSum] = numWays;
    }
    
    /**
     * @brief Computes the number of combinations to achieve the target sum using a recursive approach with memoization.
     * 
     * @param target The target sum to achieve
     * @return int The number of combinations to achieve the target sum
     */
    int recursive(int target) {
        dp.resize(target + 1, -1);
        return helper(target);
    }
    
    /**
     * @brief Computes the number of combinations to achieve the target sum using an iterative approach.
     * 
     * @param target The target sum to achieve
     * @return int The number of combinations to achieve the target sum
     */
    int iterative(int target) {
        dp.resize(target + 1, 0);
        dp[0] = 1;  // There is one way to achieve sum 0 (using no numbers)
        
        for (int i = 1; i <= target; i++) {
            for (int num : nums) {
                if (num <= i) {
                    dp[i] += dp[i - num];
                }
            }
        }
        
        return dp[target];
    }
    
    /**
     * @brief Main function to compute the number of combinations to achieve the target sum.
     * 
     * This function defaults to using the recursive approach.
     * 
     * @param nums The input vector of distinct integers
     * @param target The target sum to achieve
     * @return int The number of combinations to achieve the target sum
     */
    int combinationSum4(vector<int>& nums, int target) {
        this->nums = nums;
        return recursive(target);
    }
};

