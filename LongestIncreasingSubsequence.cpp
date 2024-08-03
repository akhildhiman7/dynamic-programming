/**
 * @file LongestIncreasingSubsequence.cpp
 * @brief Solution to the LeetCode problem "Longest Increasing Subsequence"
 * @link https://leetcode.com/problems/longest-increasing-subsequence/
 * 
 * Algorithm Explanation:
 * 
 * Problem Statement:
 * Given an integer array nums, return the length of the longest strictly increasing subsequence.
 * 
 * To solve this problem, we can use two approaches: 
 * a dynamic programming approach and a binary search approach.
 * 
 * Dynamic Programming Approach:
 * 1. Create a dp array of the same size as nums, initialized to 1.
 * 2. For each element in nums, iterate over the previous elements to find the longest subsequence.
 * 3. Update the dp array with the length of the longest subsequence found.
 * 4. The final result is the maximum value in the dp array.
 * 
 * Binary Search Approach:
 * 1. Create a temp array to keep track of the indices of the smallest end elements of increasing subsequences.
 * 2. For each element in nums, use binary search to find its position in temp.
 * 3. Update temp with the current element's index.
 * 4. The final result is the length of the temp array.
 * 
 * The binary search approach is used as the default method in our solution.
 */

#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

class Solution {
public:
    /**
     * @brief Prints the elements of a vector.
     * 
     * @param v The vector to print.
     */
    void printVector(const vector<int> &v) {
        for (const auto &i : v) {
            cout << i << " ";
        }
        cout << endl;
    }
    
    /**
     * @brief Computes the length of the longest increasing subsequence using dynamic programming.
     * 
     * @param nums The input vector of integers.
     * @return int The length of the longest increasing subsequence.
     */
    int dynamicProgramming(vector<int> &nums) {
        vector<int> dp(nums.size(), 1);
        int maxLength = 1;
        
        for (int i = 1; i < nums.size(); i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i]) {
                    dp[i] = max(dp[i], dp[j] + 1);
                    maxLength = max(maxLength, dp[i]);
                }
            }
        }
        
        return maxLength;
    }
    
    /**
     * @brief Finds the index of the smallest element in temp that is greater than or equal to val.
     * 
     * @param nums The input vector of integers.
     * @param temp The vector of indices of the smallest end elements of increasing subsequences.
     * @param val The value to find the ceil for.
     * @param n The current length of temp.
     * @return int The index of the smallest element greater than or equal to val.
     */
    int getCeilValue(const vector<int> &nums, const vector<int> &temp, int val, int n) {
        int start = 0, end = n;
        
        while (start <= end) {
            int mid = start + (end - start) / 2;
            
            if (nums[temp[mid]] == val) {
                return mid;
            } else if (nums[temp[mid]] < val) {
                start = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        
        return start;
    }
    
    /**
     * @brief Computes the length of the longest increasing subsequence using binary search.
     * 
     * @param nums The input vector of integers.
     * @return int The length of the longest increasing subsequence.
     */
    int binarySearch(vector<int> &nums) {
        vector<int> temp(nums.size(), 0);
        int lastMaxLen = 0;
        
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[temp[lastMaxLen]]) {
                temp[++lastMaxLen] = i;
            } else {
                if (nums[i] <= nums[temp[0]]) {
                    temp[0] = i;
                } else {
                    int index = getCeilValue(nums, temp, nums[i], lastMaxLen);
                    temp[index] = i;
                }
            }
        }
        
        return lastMaxLen + 1;
    }
    
    /**
     * @brief Computes the length of the longest increasing subsequence.
     * 
     * This function defaults to using the binary search approach.
     * 
     * @param nums The input vector of integers.
     * @return int The length of the longest increasing subsequence.
     */
    int lengthOfLIS(vector<int>& nums) {
        return binarySearch(nums);
        // return dynamicProgramming(nums);
    }
};

