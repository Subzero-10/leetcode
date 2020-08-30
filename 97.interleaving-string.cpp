/*
 * @lc app=leetcode id=97 lang=cpp
 *
 * [97] Interleaving String
 *
 * https://leetcode.com/problems/interleaving-string/description/
 *
 * algorithms
 * Hard (30.21%)
 * Likes:    1550
 * Dislikes: 90
 * Total Accepted:    159K
 * Total Submissions: 502.9K
 * Testcase Example:  '"aabcc"\n"dbbca"\n"aadbbcbcac"'
 *
 * Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and
 * s2.
 * 
 * Example 1:
 * 
 * 
 * Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
 * Output: false
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int len1 = s1.size();
        int len2 = s2.size();
        int len3 = s3.size();
        if (len3 != len1+len2)
        {
            return false;
        }
        vector<bool> dpp(len2+1,false);
        vector<vector<bool>> dp(len1+1, dpp);
        dp[0][0] = true;
        for (int i1 = 1; i1 < len1+1; i1++)
        {
            if (s3[i1-1] == s1[i1-1] && dp[i1-1][0])
            {
                dp[i1][0] = true;
            }
        }
        for (int i2 = 1; i2 < len2+1; i2++)
        {
            if (s3[i2-1] == s2[i2-1] && dp[0][i2-1])
            {
                dp[0][i2] = true;
            }
        }
        for (int i1 = 1; i1 < len1+1; i1++)
        {
            for (int i2 = 1; i2 < len2+1; i2++)
            {
                if ((s3[i1+i2-1] == s1[i1-1] && dp[i1-1][i2]) || (s3[i1+i2-1] == s2[i2-1] && dp[i1][i2-1]))
                {
                    dp[i1][i2] = true;
                }
            }
            
        }
        return dp[len1][len2];
        
    }
};
// @lc code=end

