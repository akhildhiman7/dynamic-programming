/**
 * @file LongestCommonSubsequence.cpp
 * @brief Solution to the LeetCode problem "Longest Common Subsequence"
 * @link https://leetcode.com/problems/longest-common-subsequence/
 * 
 * Algorithm Explanation:
 * 
 * Problem Statement:
 * Given two strings text1 and text2, return the length of their longest common subsequence.
 * If there is no common subsequence, return 0.
 * 
 * To solve this problem, we can use two approaches:
 * 1. Recursive approach with memoization
 * 2. Iterative approach with dynamic programming
 * 
 * Recursive Approach with Memoization:
 * 1. Create a helper function `helper(i, j)` that returns the length of the longest common subsequence
 *    of the substrings text1[i:] and text2[j:].
 * 2. Base cases:
 *    - If `i` is equal to or greater than the length of text1 or `j` is equal to or greater than the length of text2, return 0.
 * 3. Use a memoization array `dp` to store results of subproblems to avoid redundant calculations.
 * 4. If `text1[i]` is equal to `text2[j]`, include this character in the subsequence and recursively compute the length
 *    for the substrings text1[i+1:] and text2[j+1:] and add 1 to the result.
 * 5. Otherwise, recursively compute the length by either skipping the current character of text1 or text2, and take the maximum result.
 * 6. Store the result in `dp[i][j]` and return it.
 * 
 * Iterative Approach with Dynamic Programming:
 * 1. Create a 2D dp array of size (text1.length() + 1) x (text2.length() + 1) initialized to 0.
 * 2. Iterate over the characters of text1 and text2.
 * 3. If `text1[i-1]` is equal to `text2[j-1]`, update `dp[i][j]` with `dp[i-1][j-1] + 1`.
 * 4. Otherwise, update `dp[i][j]` with the maximum value between `dp[i-1][j]` and `dp[i][j-1]`.
 * 5. The final result for the length of the longest common subsequence is given by `dp[text1.length()][text2.length()]`.
 * 
 * The iterative approach is used as the default method in our solution.
 */

#include <vector>
#include <algorithm>
#include <string>

using namespace std;

class Solution {
public:
    string text1, text2;
    vector<vector<int>> dp;
    
    /**
     * @brief Helper function to compute the length of the longest common subsequence recursively with memoization.
     * 
     * @param i The current index in text1.
     * @param j The current index in text2.
     * @return int The length of the longest common subsequence from text1[i:] and text2[j:].
     */
    int helper(int i, int j) {
        // Base case: If we have reached the end of either string, return 0
        if (i >= text1.size() || j >= text2.size()) {
            return 0;
        }
        
        // If the result is already computed, return it
        if (dp[i][j] != -1) {
            return dp[i][j];
        }
        
        // If the characters match, include this character in the subsequence
        if (text1[i] == text2[j]) {
            dp[i][j] = 1 + helper(i + 1, j + 1);
        } else {
            // Otherwise, skip the current character of either string and take the maximum result
            dp[i][j] = max(helper(i + 1, j), helper(i, j + 1));
        }
        
        return dp[i][j];
    }
    
    /**
     * @brief Computes the length of the longest common subsequence using a recursive approach with memoization.
     * 
     * @return int The length of the longest common subsequence.
     */
    int recursive() {
        dp.resize(text1.size(), vector<int>(text2.size(), -1));
        return helper(0, 0);
    }
    
    /**
     * @brief Computes the length of the longest common subsequence using an iterative approach with dynamic programming.
     * 
     * @return int The length of the longest common subsequence.
     */
    int iterative() {
        dp.resize(text1.size() + 1, vector<int>(text2.size() + 1, 0));
        
        // Iterate over each character of text1 and text2
        for (int i = 1; i <= text1.size(); i++) {
            for (int j = 1; j <= text2.size(); j++) {
                // If characters match, update dp[i][j] with dp[i-1][j-1] + 1
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = 1 + dp[i - 1][j - 1];
                } else {
                    // Otherwise, take the maximum value from the previous row or column
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        
        return dp[text1.size()][text2.size()];
    }
    
    /**
     * @brief Computes the length of the longest common subsequence.
     * 
     * This function defaults to using the iterative approach.
     * 
     * @param t1 The first input string.
     * @param t2 The second input string.
     * @return int The length of the longest common subsequence.
     */
    int longestCommonSubsequence(string t1, string t2) {
        text1 = t1;
        text2 = t2;
        
        // return recursive();
        return iterative();
    }
};

