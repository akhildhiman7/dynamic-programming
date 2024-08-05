/**
 * @file UniquePaths.cpp
 * @brief Solution to the LeetCode problem "Unique Paths"
 * @link https://leetcode.com/problems/unique-paths/
 * 
 * Algorithm Explanation:
 * 
 * Problem Statement:
 * A robot is located at the top-left corner of a m x n grid (marked 'Start' in the diagram below).
 * The robot can only move either down or right at any point in time. The robot is trying to reach 
 * the bottom-right corner of the grid (marked 'Finish' in the diagram below).
 * How many possible unique paths are there?
 * 
 * Approach:
 * - This problem can be solved using dynamic programming.
 * - We use a 2D array `dp` where `dp[i][j]` represents the number of unique paths to reach the cell (i, j).
 * 
 * Detailed Steps:
 * 1. Initialize a 2D DP array `dp` of size m x n with all elements set to 1. This is because there is only one way 
 *    to reach any cell in the first row (by moving right) or any cell in the first column (by moving down).
 * 
 * 2. Iterate through the grid starting from cell (1,1), and update each cell `dp[i][j]` with the sum of 
 *    the paths from the cell above it `dp[i-1][j]` and the cell to the left of it `dp[i][j-1]`.
 * 
 * 3. The final result is stored in the bottom-right cell of the grid `dp[m-1][n-1]`.
 * 
 * Time Complexity:
 * - O(m * n), where m is the number of rows and n is the number of columns.
 * 
 * Space Complexity:
 * - O(m * n) for the DP array.
 */

#include <vector>
using namespace std;

class Solution {
public:
    /**
     * @brief Computes the number of unique paths from top-left to bottom-right in a m x n grid.
     * 
     * @param m The number of rows in the grid
     * @param n The number of columns in the grid
     * @return int The number of unique paths
     */
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, 1));
        
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = dp[i - 1][j] + dp[i][j - 1];
            }
        }
        
        return dp[m - 1][n - 1];
    }
};

