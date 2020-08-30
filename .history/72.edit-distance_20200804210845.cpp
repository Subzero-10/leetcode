/*
 * @lc app=leetcode id=72 lang=cpp
 *
 * [72] Edit Distance
 *
 * https://leetcode.com/problems/edit-distance/description/
 *
 * algorithms
 * Hard (41.45%)
 * Likes:    4098
 * Dislikes: 57
 * Total Accepted:    287.3K
 * Total Submissions: 642.5K
 * Testcase Example:  '"horse"\n"ros"'
 *
 * Given two words word1 and word2, find the minimum number of operations
 * required to convert word1 to word2.
 * 
 * You have the following 3 operations permitted on a word:
 * 
 * 
 * Insert a character
 * Delete a character
 * Replace a character
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: word1 = "horse", word2 = "ros"
 * Output: 3
 * Explanation: 
 * horse -> rorse (replace 'h' with 'r')
 * rorse -> rose (remove 'r')
 * rose -> ros (remove 'e')
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: word1 = "intention", word2 = "execution"
 * Output: 5
 * Explanation: 
 * intention -> inention (remove 't')
 * inention -> enention (replace 'i' with 'e')
 * enention -> exention (replace 'n' with 'x')
 * exention -> exection (replace 'n' with 'c')
 * exection -> execution (insert 'u')
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int minDistance(string word1, string word2) {
        int len1 = word1.size();
        int len2 = word2.size();
        int column[len2+1];
        int pre;
        int pre1;
        for (int i = 0; i < len2+1; i++)
        {
            column[i] = i;
        }
        for (int i = 0; i < len1; i++)
        {
            pre = column[0];
            column[0] = i+1;
            for (int j = 0; j < len2; j++)
            {
                pre1 = column[j+1];
                if (word1[i] == word2[j])
                {
                    column[j+1] = min(column[j+1]+1, column[j]+1, pre);
                }
                else
                {
                    column[j+1] = min(column[j+1], column[j], pre) + 1;
                }
                pre = pre1;
            }
        }
        return column[len2];
    }
};
// @lc code=end

