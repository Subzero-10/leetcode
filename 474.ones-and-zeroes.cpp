/*
 * @lc app=leetcode id=474 lang=cpp
 *
 * [474] Ones and Zeroes
 */

// @lc code=start
class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int strlen = strs.size();
        vector<vector<int>> arr(strlen,vector<int>(2,0));
        for (int i = 0; i < strlen; i++)
        {
            for (int j = 0; j < strs[i].size(); j++)
            {
                if (strs[i][j] == '0')
                {
                    arr[i][0]++;
                }
                else
                {
                    arr[i][1]++;
                }
            }
        }
        vector<vector<int>> dp(m+1, vector<int>(n+1,0));
        for (int i = 0; i < strlen; i++)
        {
            for (int j = m; j >=0; j--)
            {
                for (int k = n; k >= 0; k--)
                {
                    if ((j-arr[i][0]>=0)&&(k-arr[i][1]>=0))
                    {
                        dp[j][k] = max(dp[j][k],dp[j-arr[i][0]][k-arr[i][1]]+1);
                    }
                }
            }
        }
        return dp[m][n];
    }
};
// @lc code=end

