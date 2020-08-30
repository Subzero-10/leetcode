/*
 * @lc app=leetcode id=59 lang=cpp
 *
 * [59] Spiral Matrix II
 *
 * https://leetcode.com/problems/spiral-matrix-ii/description/
 *
 * algorithms
 * Medium (51.49%)
 * Likes:    996
 * Dislikes: 111
 * Total Accepted:    195.2K
 * Total Submissions: 364.1K
 * Testcase Example:  '3'
 *
 * Given a positive integer n, generate a square matrix filled with elements
 * from 1 to n^2 in spiral order.
 * 
 * Example:
 * 
 * 
 * Input: 3
 * Output:
 * [
 * ⁠[ 1, 2, 3 ],
 * ⁠[ 8, 9, 4 ],
 * ⁠[ 7, 6, 5 ]
 * ]
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<int> a(n,0);
        vector<vector<int>> b(n,a);
        int column = n;
        int row = n;
        int inColumn = 0;
        int r = 0;
        int c = -1;
        int count = 1;
        //c r-1 c-1 r-2
        for (int i = 0; i < n*n; i++)
        {
            switch (inColumn)
            {
            case 0:
                c++;
                b[r][c] = i+1;
                if (count == column)
                {
                    column--;
                    count = 0;
                    inColumn = 1;
                }
                break;

            case 1:
                r++;
                b[r][c] = i+1;
                if (count == row-1)
                {
                    row--;
                    count = 0;
                    inColumn = 2;
                }
                break;

            case 2:
                c--;
                b[r][c] = i+1;
                if (count == column)
                {
                    column--;
                    count = 0;
                    inColumn = 3;
                }
                break;
                
            case 3:
                r--;
                b[r][c] = i+1;
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
        return b;
    }
};
// @lc code=end

