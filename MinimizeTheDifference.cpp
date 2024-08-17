/**
 * @file MinimizeTheDifference.cpp
 * @brief Solution to the LeetCode problem "Minimize the Difference Between Target and Chosen Elements"
 * @link https://leetcode.com/problems/minimize-the-difference-between-target-and-chosen-elements/
 * 
 * Algorithm Explanation:
 * 
 * Problem Statement:
 * Given a 2D matrix `mat` of size `m x n`, you need to choose one element from each row and calculate the sum of these elements. 
 * The goal is to minimize the absolute difference between this sum and a given `target` value.
 * 
 * Intuition:
 * The problem can be solved using dynamic programming by considering each row one by one and trying to compute the possible sums we can get 
 * from choosing one element per row. We store these results and use them to find the minimum difference from the target.
 * 
 * Approach:
 * - We start by initializing a DP table where `dp[i][cSum]` indicates whether we can reach the sum `cSum` by choosing elements from the first `i` rows.
 * - The DP function, `helper`, is recursively defined to explore all possible sums we can obtain by selecting elements from the matrix rows.
 * - The function updates the minimum difference between the computed sum and the target whenever we reach the last row.
 * - We use memoization to store already computed results to avoid redundant calculations.
 * 
 * Time Complexity:
 * - O(m * n * maxSum), where `m` is the number of rows, `n` is the number of columns, and `maxSum` is the sum of the maximum elements from each row.
 * 
 * Space Complexity:
 * - O(m * maxSum), for the DP table used to store intermediate results.
 */

#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>

using namespace std;

class Solution {
public:
    vector<vector<int>> dp;  // DP table to store intermediate results
    int minDiff = INT_MAX, target, n;

    // Recursive helper function to explore all possible sums
    void helper(vector<vector<int>>& mat, int i, int cSum) {
        // Base case: If we've processed all rows, update the minimum difference
        if (i >= mat.size()) {
            minDiff = min(minDiff, abs(cSum - target));
            return;
        }
        
        // If the current sum is already farther than the current minimum difference, stop exploring
        if (cSum - target >= minDiff) {
            return;
        }

        // If this sum has been explored before, skip it
        if (dp[i][cSum] != -1) {
            return;
        }

        // Mark the current state as visited
        dp[i][cSum] = 1;

        // Recursively explore all possible sums by choosing one element from the current row
        for (int j = 0; j < n; j++) {
            helper(mat, i + 1, cSum + mat[i][j]);
        }
    }

    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        int maxSum = 0;
        
        // Calculate the maximum possible sum (i.e., sum of max elements from each row)
        for (const auto& row : mat) {
            int rowMax = *max_element(row.begin(), row.end());
            maxSum += rowMax;
        }
        
        // Initialize the DP table
        dp.resize(mat.size(), vector<int>(maxSum + 1, -1));
        this->target = target;
        n = mat[0].size();
        
        // Start the DP process
        helper(mat, 0, 0);
        
        // Return the minimum difference found
        return minDiff;
    }
};

