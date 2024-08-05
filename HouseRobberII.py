"""
@file HouseRobberII.py
@brief Solution to the LeetCode problem "House Robber II"
@link https://leetcode.com/problems/house-robber-ii/
 
Algorithm Explanation:
 
Problem Statement:
You are a professional robber planning to rob houses along a street. Each house has a certain amount 
of money stashed. All houses at this place are arranged in a circle. That means the first house is the 
neighbor of the last one. Meanwhile, adjacent houses have security systems connected and it will 
automatically contact the police if two adjacent houses were broken into on the same night.

Given an integer array nums representing the amount of money of each house, return the maximum amount 
of money you can rob tonight without alerting the police.

Approach:
- This problem is a variation of the "House Robber" problem. Since the houses are arranged in a circle,
  we cannot rob both the first and last houses together. Therefore, we need to consider two cases:
  1. Rob houses from the first house to the second-to-last house.
  2. Rob houses from the second house to the last house.
- We can solve this problem using dynamic programming.

Detailed Steps:
1. **Helper Function**:
    - Define a helper function `helper(nums)` that returns the maximum amount of money that can be 
      robbed from a linear arrangement of houses.
    - Create a DP array `dp` of the same size as `nums`.
    - Set `dp[0]` to `nums[0]` as the only option is to rob the first house.
    - If there is more than one house, set `dp[1]` to the maximum of robbing the first or the second house.
    - Iterate over the remaining houses and compute the maximum amount of money that can be robbed 
      up to that house.
    - The final result is the maximum value in the `dp` array.

2. **Main Function**:
    - Handle the base case where the length of `nums` is 1. In such cases, return the value of the only house.
    - Compute the maximum money that can be robbed in two cases:
      1. Exclude the last house and rob from the first house to the second-to-last house.
      2. Exclude the first house and rob from the second house to the last house.
    - Return the maximum value obtained from the two cases.

Time Complexity:
- O(n), where n is the length of the `nums` array.

Space Complexity:
- O(n) for the dynamic programming array.

"""

from typing import List

class Solution:
    def rob(self, nums: List[int]) -> int:
        # Handle the base case where the length of nums is 1 or 2
        if len(nums) == 1:
            return nums[0]
        elif len(nums) == 2:
            return max(nums)
        
        def helper(nums: List[int]) -> int:
            if not nums:
                return 0
            if len(nums) == 1:
                return nums[0]
            
            dp = [0] * len(nums)
            dp[0] = nums[0]
            dp[1] = max(nums[0], nums[1])

            for i in range(2, len(nums)):
                dp[i] = max(nums[i] + dp[i - 2], dp[i - 1])

            return dp[-1]
        
        # Case 1: Exclude the last house
        case1 = helper(nums[:-1])
        
        # Case 2: Exclude the first house
        case2 = helper(nums[1:])
        
        return max(case1, case2)

