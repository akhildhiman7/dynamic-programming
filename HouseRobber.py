"""
@file HouseRobber.py
@brief Solution to the LeetCode problem "House Robber"
@link https://leetcode.com/problems/house-robber/
 
Algorithm Explanation:
 
Problem Statement:
You are a professional robber planning to rob houses along a street. Each house has a certain amount 
of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses 
have security systems connected and it will automatically contact the police if two adjacent houses 
were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount 
of money you can rob tonight without alerting the police.
 
Approach:
- We can solve this problem using dynamic programming.
- We have two approaches: recursive with memoization and iterative.
 
Detailed Steps:
1. **Recursive Approach with Memoization**:
    - Define a helper function `recursive(nums, i)` that returns the maximum amount of money that can 
      be robbed from the `i`-th house to the end of the list.
    - Base cases:
      - If `i` is greater than or equal to the length of nums, return 0.
    - Use a memoization dictionary `dp` to store the results of subproblems.
    - If the result for `dp[i]` is already computed, return `dp[i]`.
    - Compute the maximum of two scenarios:
      - Robbing the current house `nums[i]` and moving to the house at index `i + 2`.
      - Skipping the current house and moving to the house at index `i + 1`.
    - Store the result in `dp[i]` and return it.
 
2. **Iterative Approach**:
    - Create a DP array `dp` of the same size as `nums`.
    - Set `dp[0]` to `nums[0]` as the only option is to rob the first house.
    - Set `dp[1]` to the maximum of robbing the first or the second house.
    - Iterate over the remaining houses and compute the maximum amount of money that can be robbed 
      up to that house.
    - The final result is the maximum of the last two values in the `dp` array.
 
Time Complexity:
- O(n), where n is the length of the `nums` array.
 
Space Complexity:
- O(n) for the recursive approach due to memoization.
- O(1) additional space for the iterative approach.
"""

from typing import List

class Solution:
    def rob(self, nums: List[int]) -> int:
        dp = {}
        
        def recursive(nums, i):
            if i >= len(nums):
                return 0
            if i in dp:
                return dp[i]

            dp[i] = max(nums[i] + recursive(nums, i + 2), recursive(nums, i + 1))
            return dp[i]
        
        def iterative():
            if len(nums) == 1:
                return nums[0]
            dp = [0] * len(nums)
            dp[0] = nums[0]
            dp[1] = max(nums[0], nums[1])
            
            for i in range(2, len(nums)):
                dp[i] = max(nums[i] + dp[i - 2], dp[i - 1])
            
            return dp[-1]
        
        if len(nums) == 1:
            return nums[0]
        
        # return recursive(nums, 0)
        return iterative()

