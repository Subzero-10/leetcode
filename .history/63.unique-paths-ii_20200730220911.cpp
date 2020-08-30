/*
 * @lc app=leetcode id=63 lang=cpp
 *
 * [63] Unique Paths II
 *
 * https://leetcode.com/problems/unique-paths-ii/description/
 *
 * algorithms
 * Medium (33.94%)
 * Likes:    1776
 * Dislikes: 242
 * Total Accepted:    300K
 * Total Submissions: 869.5K
 * Testcase Example:  '[[0,0,0],[0,1,0],[0,0,0]]'
 *
 * A robot is located at the top-left corner of a m x n grid (marked 'Start' in
 * the diagram below).
 * 
 * The robot can only move either down or right at any point in time. The robot
 * is trying to reach the bottom-right corner of the grid (marked 'Finish' in
 * the diagram below).
 * 
 * Now consider if some obstacles are added to the grids. How many unique paths
 * would there be?
 * 
 * 
 * 
 * An obstacle and empty space is marked as 1 and 0 respectively in the grid.
 * 
 * Note: m and n will be at most 100.
 * 
 * Example 1:
 * 
 * 
 * Input:
 * [
 * [0,0,0],
 * [0,1,0],
 * [0,0,0]
 * ]
 * Output: 2
 * Explanation:
 * There is one obstacle in the middle of the 3x3 grid above.
 * There are two ways to reach the bottom-right corner:
 * 1. Right -> Right -> Down -> Down
 * 2. Down -> Down -> Right -> Right
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid[0].size();
        int n = obstacleGrid.size();
        vector<int> a(m,1);
        vector<vector<int>> b(n,a);
        bool have1 = false;
        for (int i = 1; i < m; i++)
        {
            if (have1)
            {
                b[0][i] = 0;
                continue;
            }
            if (obstacleGrid[i][j] == 1)
            {
                b[0][1] = 0;
                have1 = true;
            }
        }
        have1 = false;
        for (int i = 1; i < n; i++)
        {
            if (have1)
            {
                b[i][0] = 0;
                continue;
            }
            if (obstacleGrid[i][j] == 1)
            {
                b[i][0] = 0;
                have1 = true;
            }
        }
        for (int i = 1; i < n; i++)
        {
            for (int j = 1; j < m; j++)
            {
                if (obstacleGrid[i][j] == 1)
                {
                    b[i][j] = 0;
                }
                else
                {
                    b[i][j] = b[i-1][j] + b[i][j-1];
                }
            }
        }
        return b[n-1][m-1];
    }
};
// @lc code=end

