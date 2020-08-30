/*
 * @lc app=leetcode id=91 lang=cpp
 *
 * [91] Decode Ways
 *
 * https://leetcode.com/problems/decode-ways/description/
 *
 * algorithms
 * Medium (23.72%)
 * Likes:    2840
 * Dislikes: 2942
 * Total Accepted:    415.6K
 * Total Submissions: 1.7M
 * Testcase Example:  '"12"'
 *
 * A message containing letters from A-Z is being encoded to numbers using the
 * following mapping:
 * 
 * 
 * 'A' -> 1
 * 'B' -> 2
 * ...
 * 'Z' -> 26
 * 
 * 
 * Given a non-empty string containing only digits, determine the total number
 * of ways to decode it.
 * 
 * Example 1:
 * 
 * 
 * Input: "12"
 * Output: 2
 * Explanation: It could be decoded as "AB" (1 2) or "L" (12).
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: "226"
 * Output: 3
 * Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2
 * 6).
 * 
 */

// @lc code=start
class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp(2,1);
        if (s[0] == '0')
        {
            return 0;
        }
        
        for (int i = 1; i < s.size(); i++)
        {
            if ((s[i]-'0')<=6 && (s[i-1]-'0')<=2)
            {
                dp.push_back(dp[i] + dp[i-1]);
            }
            else
            {
                dp.push_back(dp[i]);
            }
        }
        return dp.back();
    }
};
// @lc code=end

