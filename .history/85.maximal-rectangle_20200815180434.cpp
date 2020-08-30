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
        if (matrix.empty())
        {
            return 0;
        }
        vector<int> r(matrix[0].size()+1, 0);
        vector<vector<int>> rc(matrix.size()+1, r);
        for (int i = 0; i < matrix.size(); i++)
        {
            for (int j = 0; j < matrix[0].size(); j++)
            {
                if (matrix[i][j] == '1')
                {
                    rc[i][j+1] = rc[i][j] + 1;
                }
                else
                {
                    rc[i][j+1] = 0;
                }
            }
        }
        int maxa = 0;
        for (int j = matrix[0].size(); j >=1; j--)
        {
            stack<int> s;
            for (int i = 0; i < matrix.size()+1; i++)
            {
                if (!s.empty())
                {
                    while (rc[s.top()][j] > rc[i][j])
                    {
                        int pos = s.top();
                        printf("%d",pos);
                        s.pop();
                        if (s.empty())
                        {
                            maxa = max((i-0)*rc[pos][j], maxa);
                            break;
                        }
                        else
                        {
                            maxa = max((i-s.top()-1)*rc[pos][j], maxa);
                        }
                    }
                }
                s.push(i);
            }
        }
        return maxa;
    }
};
// @lc code=end

