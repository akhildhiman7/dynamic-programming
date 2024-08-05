/**
 * @file JumpGame.cpp
 * @brief Solution to the LeetCode problem "Jump Game"
 * @link https://leetcode.com/problems/jump-game/
 * 
 * Algorithm Explanation:
 * 
 * Problem Statement:
 * Given an array of non-negative integers `nums`, you are initially positioned at the first index of the array.
 * Each element in the array represents your maximum jump length at that position.
 * Determine if you are able to reach the last index.
 * 
 * Approach:
 * - Use a greedy algorithm to keep track of the farthest index that can be reached.
 * - Iterate through the array and update the farthest reachable index.
 * - If at any point the current index is greater than the farthest reachable index, return false.
 * - If the farthest reachable index is greater than or equal to the last index, return true.
 * 
 * Time Complexity:
 * - O(n), where n is the length of the `nums` array.
 * 
 * Space Complexity:
 * - O(1), as we are using a constant amount of extra space.
 */

#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    /**
     * @brief Determines if it is possible to reach the last index of the array.
     * 
     * @param nums The input vector of non-negative integers representing jump lengths
     * @return bool True if the last index can be reached, False otherwise
     */
    bool canJump(vector<int>& nums) {
        int maxReach = nums[0];
        
        for (int i = 0; i < nums.size() && maxReach >= i; i++) {
            maxReach = max(maxReach, i + nums[i]);
        }
        
        return maxReach >= nums.size() - 1;
    }
};

