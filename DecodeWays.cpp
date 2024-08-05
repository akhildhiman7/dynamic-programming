/**
 * @file DecodeWays.cpp
 * @brief Solution to the LeetCode problem "Decode Ways"
 * @link https://leetcode.com/problems/decode-ways/
 * 
 * Algorithm Explanation:
 * 
 * Problem Statement:
 * A message containing letters from A-Z can be encoded into numbers using the following mapping:
 * 'A' -> 1
 * 'B' -> 2
 * ...
 * 'Z' -> 26
 * 
 * Given a non-empty string containing only digits, determine the total number of ways to decode it.
 * 
 * Approach:
 * - We can solve this problem using dynamic programming.
 * - We need to keep track of the number of ways to decode the string up to each character, considering both single and double digit numbers.
 * 
 * Detailed Steps:
 * 1. Initialize variables:
 *    - `v` to represent the number of ways to decode the string ending at the previous character.
 *    - `f` to represent the number of ways to decode the string ending at the character before the previous character.
 * 
 * 2. Iterate through the string:
 *    - If the current character is '0':
 *      - It cannot start a new sequence on its own.
 *      - It can only form a valid two-digit number with '1' or '2' before it (i.e., "10" or "20").
 *      - If the preceding character is not '1' or '2', the string is invalid.
 * 
 *    - If the current character is not '0':
 *      - It can form a valid sequence on its own.
 *      - Check if the current and the previous characters together form a valid two-digit number (10 to 26).
 * 
 * 3. Update `v` and `f` accordingly.
 * 
 * 4. Return the total number of ways to decode the string.
 * 
 * Time Complexity:
 * - O(n), where n is the length of the string.
 * 
 * Space Complexity:
 * - O(1), as we are using a constant amount of extra space.
 */

#include <string>
using namespace std;

class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if (n == 0 || s[0] == '0') return 0;  // Immediate return if starts with '0' or is empty

        int v = 1;  // Initialize vacant positions with 1 way (empty string case)
        int f = 0;  // Initially, no full sequences

        for (int i = 0; i < n; i++) {
            int newV = 0, newF = 0;
            if (s[i] == '0') {
                // '0' cannot start a new sequence, so newV = 0
                if (i > 0 && (s[i-1] == '1' || s[i-1] == '2')) {
                    // '0' can only form a full sequence with '1' or '2' before it
                    newF = v;  // Transfer previous v to f because it completes those sequences
                } else {
                    // Invalid sequence
                    return 0;
                }
            } else {
                // Current digit can start a new sequence on its own if not '0'
                newV = v + f;
                // Check for two-digit number formation
                if (i > 0 && s[i-1] != '0') {
                    int twoDigit = (s[i-1] - '0') * 10 + (s[i] - '0');
                    if (twoDigit <= 26 && twoDigit >= 10) {
                        newF = v;
                    }
                }
            }
            // Update v and f
            v = newV;
            f = newF;
        }

        return v + f;  // Total ways to decode the string
    }
};

