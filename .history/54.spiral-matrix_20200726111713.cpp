/*
 * @lc app=leetcode id=54 lang=cpp
 *
 * [54] Spiral Matrix
 *
 * https://leetcode.com/problems/spiral-matrix/description/
 *
 * algorithms
 * Medium (32.84%)
 * Likes:    2429
 * Dislikes: 574
 * Total Accepted:    374.6K
 * Total Submissions: 1.1M
 * Testcase Example:  '[[1,2,3],[4,5,6],[7,8,9]]'
 *
 * Given a matrix of m x n elements (m rows, n columns), return all elements of
 * the matrix in spiral order.
 * 
 * Example 1:
 * 
 * 
 * Input:
 * [
 * ⁠[ 1, 2, 3 ],
 * ⁠[ 4, 5, 6 ],
 * ⁠[ 7, 8, 9 ]
 * ]
 * Output: [1,2,3,6,9,8,7,4,5]
 * 
 * 
 * Example 2:
 * 
 * Input:
 * [
 * ⁠ [1, 2, 3, 4],
 * ⁠ [5, 6, 7, 8],
 * ⁠ [9,10,11,12]
 * ]
 * Output: [1,2,3,4,8,12,11,10,9,5,6,7]
 * 
 */

// @lc code=start
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int column = matrix[0].size();
        int step = row*column;
        int inColumn = 0;
        int r = 0;
        int c = -1;
        int count = 1;
        vector<int> output;
        //c r-1 c-1 r-2
        for (int i = 0; i < step; i++)
        {
            printf("%d,%d\n",i,count);
            switch (inColumn)
            {
            case 0:
                c = c+count;
                output.push_back(matrix[r][c]);
                if (count == column)
                {
                    column--;
                    count = 0;
                    inColumn = 1;
                }
                break;

            case 1:
                r = r+count;
                output.push_back(matrix[r][c]);
                if (count == row-1)
                {
                    row--;
                    count = 0;
                    inColumn = 2;
                }
                break;

            case 2:
                c = c-count;
                output.push_back(matrix[r][c]);
                if (count == column)
                {
                    column--;
                    count = 0;
                    inColumn = 3;
                }
                break;
                
            case 3:
                r = r-count;
                output.push_back(matrix[r][c]);
                if (count == row-1)
                {
                    row--;
                    count = 0;
                    inColumn = 0;
                }
                break;
            default:
                break;
            }
            count++;
        }
        return output;
    }
};
// @lc code=end

