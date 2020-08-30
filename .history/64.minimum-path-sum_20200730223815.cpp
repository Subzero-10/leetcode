/*
 * @lc app=leetcode id=64 lang=cpp
 *
 * [64] Minimum Path Sum
 *
 * https://leetcode.com/problems/minimum-path-sum/description/
 *
 * algorithms
 * Medium (51.10%)
 * Likes:    3141
 * Dislikes: 63
 * Total Accepted:    429.7K
 * Total Submissions: 791.1K
 * Testcase Example:  '[[1,3,1],[1,5,1],[4,2,1]]'
 *
 * Given a m x n grid filled with non-negative numbers, find a path from top
 * left to bottom right which minimizes the sum of all numbers along its path.
 * 
 * Note: You can only move either down or right at any point in time.
 * 
 * Example:
 * 
 * 
 * Input:
 * [
 * [1,3,1],
 * ⁠ [1,5,1],
 * ⁠ [4,2,1]
 * ]
 * Output: 7
 * Explanation: Because the path 1→3→1→1→1 minimizes the sum.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid[0].size();
        int n = grid.size();
        vector<int> a(m,0);
        vector<vector<int>> b(n,a);
        int plus = 0;
        for (int i = 0; i < m; i++)
        {
            b[0][i] = grid[0][i] + plus;
            plus = b[0][i];
        }
        printf("1");
        plus = 0;
        for (int i = 0; i < n; i++)
        {
            b[i][0] = grid[i][0] + plus;
            plus = b[0][i];
        }
        printf("2");
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                b[i][j] = grid[i][j] + min(b[i-1][j],b[i][j-1]);
            }
            printf("3");
        }
        return b[n-1][m-1];
    }
};
// @lc code=end

