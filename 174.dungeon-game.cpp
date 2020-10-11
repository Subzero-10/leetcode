/*
 * @lc app=leetcode id=174 lang=cpp
 *
 * [174] Dungeon Game
 */

// @lc code=start
class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int row = dungeon.size();
        int col = dungeon[0].size();
        vector<vector<int>> dp(row+1,vector<int>(col+1,1));
        for (int i = 0; i < col-1; i++)
        {
            dp[row][i] = INT_MAX;
        }
        for (int i = 0; i < row-1; i++)
        {
            dp[i][col] = INT_MAX;
        }
        for (int i = row-1; i >=0; i--)
        {
            for (int j = col-1; j >=0; j--)
            {
                if (dungeon[i][j]<dp[i+1][j]&&dungeon[i][j]<dp[i][j+1])
                {
                    dp[i][j] = min(dp[i+1][j],dp[i][j+1]) - dungeon[i][j];
                }
            }
        }
        return dp[0][0];
    }
};
// @lc code=end

