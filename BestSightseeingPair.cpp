/**
 * @file BestSightseeingPair.cpp
 * @brief Solution to the LeetCode problem "Best Sightseeing Pair"
 * @link https://leetcode.com/problems/best-sightseeing-pair/
 * 
 * Algorithm Explanation:
 * 
 * Problem Statement:
 * Given an array `values` where `values[i]` represents the value of a sightseeing spot at index `i`,
 * the goal is to find the maximum score of a pair `(i, j)` where `i < j`. The score of the pair is defined as
 * `values[i] + values[j] + i - j`.
 * 
 * Intuition:
 * The problem can be broken down into finding the maximum sum of the expression `values[i] + i + values[j] - j`
 * for `i < j`. We can split the problem into two parts:
 * 1. Maintaining the maximum possible value of `values[i] + i` as we iterate through the array.
 * 2. For each `j`, we calculate `values[j] - j` and add it to the maximum value from the first part.
 * 
 * This approach ensures that we only need to iterate through the array once while maintaining the necessary
 * information to calculate the maximum possible score.
 * 
 * Approach:
 * - Initialize variables to keep track of the maximum score and the maximum value of `values[i] + i`.
 * - Iterate through the array and for each element, calculate the score using the current value of `values[j] - j`
 *   and the maximum value of `values[i] + i`.
 * - Update the maximum score if the current score is higher.
 * - After calculating the score for each `j`, update the maximum value of `values[i] + i` for the next iteration.
 * 
 * Time Complexity:
 * - O(n), where `n` is the number of elements in the `values` array.
 * 
 * Space Complexity:
 * - O(1), as we are only using a few variables to keep track of the maximum scores.
 */

#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int maxSum = 0;
        int maxLeft = values[0] + 0; // This keeps track of the maximum values[i] + i
        
        for (int j = 1; j < values.size(); ++j) {
            maxSum = max(maxSum, maxLeft + values[j] - j); // Calculate the score for the current pair
            maxLeft = max(maxLeft, values[j] + j); // Update the maximum values[i] + i for the next pair
        }
        
        return maxSum;
    }
};

