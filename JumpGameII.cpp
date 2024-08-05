/**
 * @file JumpGameII.cpp
 * @brief Solution to the LeetCode problem "Jump Game II"
 * @link https://leetcode.com/problems/jump-game-ii/
 * 
 * Algorithm Explanation:
 * 
 * Problem Statement:
 * Given an array of non-negative integers `nums`, where each element represents your maximum jump length at that position,
 * determine the minimum number of jumps required to reach the last index.
 * 
 * Approach:
 * - Use a greedy algorithm to keep track of the farthest index that can be reached.
 * - Iterate through the array and update the farthest reachable index.
 * - Use `currEnd` to keep track of the end of the range of the current jump.
 * - When the current index `i` reaches `currEnd`, increment the step count and update `currEnd` to `maxReachable`.
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
     * @brief Determines the minimum number of jumps required to reach the last index of the array.
     * 
     * @param nums The input vector of non-negative integers representing jump lengths
     * @return int The minimum number of jumps to reach the last index
     */
    int jump(vector<int>& nums) {
        int maxReachable = 0, currEnd = 0, steps = 0;
        
        for (int i = 0; i < nums.size() - 1; i++) {
            maxReachable = max(i + nums[i], maxReachable);
            
            if (i == currEnd) {
                currEnd = maxReachable;
                steps++;
            }
        }
        
        return steps;
    }
};

