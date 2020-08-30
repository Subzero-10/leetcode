/*
 * @lc app=leetcode id=58 lang=cpp
 *
 * [58] Length of Last Word
 *
 * https://leetcode.com/problems/length-of-last-word/description/
 *
 * algorithms
 * Easy (32.45%)
 * Likes:    673
 * Dislikes: 2471
 * Total Accepted:    382.1K
 * Total Submissions: 1.2M
 * Testcase Example:  '"Hello World"'
 *
 * Given a string s consists of upper/lower-case alphabets and empty space
 * characters ' ', return the length of last word (last word means the last
 * appearing word if we loop from left to right) in the string.
 * 
 * If the last word does not exist, return 0.
 * 
 * Note: A word is defined as a maximal substring consisting of non-space
 * characters only.
 * 
 * Example:
 * 
 * 
 * Input: "Hello World"
 * Output: 5
 * 
 * 
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int lengthOfLastWord(string s) {
        int lenWord = 0;
        int len = s.size();
        bool findWord = false;
        for (int i = len-1; i >= 0; i--)
        {
            if (s[i]==' ')
            {
                if (findWord)
                {
                    return lenWord;
                }
            }
            else
            {
                if (findWord)
                {
                    lenWord++;
                }
                else
                {
                    lenWord++;
                    findWord = true;
                }
            }
        }
        return lenWord;
    }
};
// @lc code=end

