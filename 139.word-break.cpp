/*
 * @lc app=leetcode id=139 lang=cpp
 *
 * [139] Word Break
 */

// @lc code=start
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int len = s.size();
        int diclen = wordDict.size();
        if (len == 0 || diclen == 0)
        {
            return false;
        }
        
        vector<bool> dp(len+1,false);
        dp[0] = true;
        for (int i = 1; i < len+1; i++)
        {
            if (dp[i-1])
            {
                for (int j = 0; j < diclen; j++)
                {
                    int wordlen = wordDict[j].size();
                    if (s.substr(i-1, wordlen) == wordDict[j])
                    {
                        dp[i-1+wordlen] = true;
                    }
                }
            }
        }
        return dp[len];
    }
};
// @lc code=end

