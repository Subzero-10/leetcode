/*
 * @lc app=leetcode id=115 lang=cpp
 *
 * [115] Distinct Subsequences
 */

// @lc code=start
class Solution {
public:
    int numDistinct(string s, string t) {
        vector<int> c((int)s.size()+1);
        vector<int> dp((int)t.size()+1);
        for (int i = 1; i < (int)t.size()+1; i++)
        {
            for (int j = 1; j < (int)s.size()+1; j++)
            {
                if (s[j-1] == t[i-1])
                {
                    dp[i][j] = dp[i][j-1] + dp[i-1][j-1];
                }
            }
        }
        return dp[(int)t.size()][(int)s.size()];
    }
};
// @lc code=end

