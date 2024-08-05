/**
 * @file WordBreak.cpp
 * @brief Solution to the LeetCode problem "Word Break"
 * @link https://leetcode.com/problems/word-break/
 * 
 * Algorithm Explanation:
 * 
 * Problem Statement:
 * Given a non-empty string s and a dictionary wordDict containing a list of non-empty words,
 * determine if s can be segmented into a sequence of one or more dictionary words.
 * 
 * Approach:
 * - Use a Trie to store the dictionary words and dynamic programming to check if the string s can be segmented.
 * 
 * Detailed Steps:
 * 1. **Trie Construction**:
 *    - Insert each word from wordDict into the Trie.
 *    - Each node in the Trie contains a flag indicating whether it marks the end of a valid word.
 * 
 * 2. **Recursive Check with Memoization**:
 *    - Initialize the recursive check from the start of the string 's'.
 *    - Use a recursive function `helper` to match substrings of 's' against words in the Trie.
 *    - If a match is found, recursively attempt to match the remaining substring.
 *    - Use memoization to store results of subproblems to avoid redundant calculations.
 * 
 * Time Complexity:
 * - O(n * m), where n is the length of the string 's' and m is the average length of the words in wordDict.
 * 
 * Space Complexity:
 * - O(N), where N is the total number of characters in all words of wordDict combined, required for storing the Trie.
 */

#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class TrieNode {
public:
    bool isEnd;
    vector<TrieNode*> children;

    TrieNode() : isEnd(false), children(26, nullptr) {}
};

class Solution {
public:
    TrieNode* globalRoot;
    unordered_map<int, bool> dp;  // Memoization for storing results of subproblems
    string s;
    vector<string> wordDict;

    Solution() {
        globalRoot = new TrieNode();
    }

    ~Solution() {
        clearTrie(globalRoot);  // Properly deallocating Trie nodes
    }

    /**
     * @brief Insert word into Trie
     * 
     * @param root The root node of the Trie
     * @param word The word to insert
     * @param i The current index in the word
     * @return TrieNode* The updated root node
     */
    TrieNode* insert(TrieNode* root, const string& word, int i) {
        if (i >= word.size()) {
            root->isEnd = true;
            return root;
        }

        if (root->children[word[i] - 'a'] == nullptr) {
            root->children[word[i] - 'a'] = new TrieNode();
        }

        root->children[word[i] - 'a'] = insert(root->children[word[i] - 'a'], word, i + 1);
        return root;
    }

    /**
     * @brief Initialize the Trie with words from the dictionary
     */
    void initializeTrie() {
        for (const auto& word : wordDict) {
            globalRoot = insert(globalRoot, word, 0);
        }
    }

    /**
     * @brief Check for string in Trie from index i with optional override
     * 
     * @param root The root node of the Trie
     * @param i The current index in the string s
     * @param overRide Flag to skip the end check
     * @return pair<TrieNode*, int> The Trie node and the new index in the string
     */
    pair<TrieNode*, int> checkForString(TrieNode* root, int i, int overRide) {
        if (!root) {
            return {root, 0};
        }

        if (overRide != 1 && root->isEnd) {  // Found a string ending here
            return {root, i};  // Return success with the last index i.e., length of the string
        }

        if (i >= s.size() || !root->children[s[i] - 'a']) {  // Input string index out of bounds or no children found further
            return {nullptr, 0};
        }

        return checkForString(root->children[s[i] - 'a'], i + 1, 0);
    }

    /**
     * @brief Recursive helper function to check word break
     * 
     * @param i The current index in the string s
     * @return bool True if the string can be segmented, False otherwise
     */
    bool helper(int i) {
        if (i == s.size()) {
            return true;
        } else if (i > s.size()) {
            return false;
        }

        if (dp.count(i)) {
            return dp[i];
        }

        int k = i;
        int overRide = 0;
        TrieNode* rootCopy = globalRoot;

        while (k < s.size()) {
            auto [node, newIndex] = checkForString(rootCopy, k, overRide);
            if (node != nullptr) {
                if (helper(newIndex)) {
                    return dp[i] = true;
                }
                overRide = 1;  // Allow continuation from the last successful node
            } else {
                break;
            }
            k = newIndex;
            rootCopy = node;
        }

        return dp[i] = false;
    }

    /**
     * @brief Main function to check if the word can be segmented
     * 
     * @param s The input string
     * @param wordDict The dictionary of words
     * @return bool True if the string can be segmented, False otherwise
     */
    bool wordBreak(string s, vector<string>& wordDict) {
        this->s = s;
        this->wordDict = wordDict;

        initializeTrie();
        return helper(0);
    }

private:
    /**
     * @brief Helper function to clear the Trie and free memory
     * 
     * @param node The current Trie node
     */
    void clearTrie(TrieNode* node) {
        if (node) {
            for (auto child : node->children) {
                clearTrie(child);
            }
            delete node;
        }
    }
};

