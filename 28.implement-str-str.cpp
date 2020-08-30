/*
 * @lc app=leetcode id=28 lang=cpp
 *
 * [28] Implement strStr()
 *
 * https://leetcode.com/problems/implement-strstr/description/
 *
 * algorithms
 * Easy (33.83%)
 * Likes:    1366
 * Dislikes: 1753
 * Total Accepted:    609.2K
 * Total Submissions: 1.8M
 * Testcase Example:  '"hello"\n"ll"'
 *
 * Implement strStr().
 * 
 * Return the index of the first occurrence of needle in haystack, or -1 if
 * needle is not part of haystack.
 * 
 * Example 1:
 * 
 * 
 * Input: haystack = "hello", needle = "ll"
 * Output: 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: haystack = "aaaaa", needle = "bba"
 * Output: -1
 * 
 * 
 * Clarification:
 * 
 * What should we return when needle is an empty string? This is a great
 * question to ask during an interview.
 * 
 * For the purpose of this problem, we will return 0 when needle is an empty
 * string. This is consistent to C's strstr() and Java's indexOf().
 * 
 */

// @lc code=start
class Solution {
public:
    int strStr(string haystack, string needle) {
        if (!needle.compare(""))
        {
            return 0;
        }
        int needlePos = 0;
        int needleSize = needle.length();
        for (int i = 0; i < haystack.length(); i++)
        {
            if (haystack[i] == needle[needlePos])
            {
                needlePos++;
            }
            else
            {
                
                if (needlePos)
                {
                    i = i-needlePos;
                }
                needlePos = 0;
                
            }
            
            if (needlePos == needleSize)
            {
                return i-needlePos+1;
            }
        }
        return -1;
        
    }
};
// @lc code=end

