/*
 * @lc app=leetcode id=85 lang=cpp
 *
 * [85] Maximal Rectangle
 *
 * https://leetcode.com/problems/maximal-rectangle/description/
 *
 * algorithms
 * Hard (36.06%)
 * Likes:    2967
 * Dislikes: 71
 * Total Accepted:    184K
 * Total Submissions: 487K
 * Testcase Example:  '[["1","0","1","0","0"],["1","0","1","1","1"],["1","1","1","1","1"],["1","0","0","1","0"]]'
 *
 * Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle
 * containing only 1's and return its area.
 * 
 * Example:
 * 
 * 
 * Input:
 * [
 * ⁠ ["1","0","1","0","0"],
 * ⁠ ["1","0","1","1","1"],
 * ⁠ ["1","1","1","1","1"],
 * ⁠ ["1","0","0","1","0"]
 * ]
 * Output: 6
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int maxa = 0;
        for (int i = 0; i < matrix.size(); i++)
        {
            int left = -1;
            for (int j = 0; j < matrix[0].size(); j++)
            {
                if (matrix[i][j] == '1')
                {
                    if (left == -1)
                    {
                        left = j;
                    }
                }
                else
                {
                    if (left != -1)
                    {
                        bool isBreak = false;
                        int row = i;
                        for (int k = i+1; k < matrix.size(); k++)
                        {
                            for (int l = left; l < j; l++)
                            {
                                if (matrix[k][l] == '0')
                                {
                                    isBreak = true;
                                    break;
                                }
                                row = k;
                            }
                            if (isBreak)
                            {
                                break;
                            }
                        }
                        maxa = max(maxa, (row-i+1)*(j-left));
                    }
                    left = -1;
                }
            }
            if (left != -1)
            {
                bool isBreak = false;
                int row = i;
                for (int k = i+1; k < matrix.size(); k++)
                {
                    for (int l = left; l < matrix[0].size(); l++)
                    {
                        if (matrix[k][l] == '0')
                        {
                            isBreak = true;
                            break;
                        }
                        row = k;
                    }
                    if (isBreak)
                    {
                        break;
                    }
                }
                maxa = max(maxa, (row-i)*((int)matrix[0].size()-left));
            }
        }
        return maxa;
    }
};
// @lc code=end

