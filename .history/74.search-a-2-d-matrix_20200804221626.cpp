/*
 * @lc app=leetcode id=74 lang=cpp
 *
 * [74] Search a 2D Matrix
 *
 * https://leetcode.com/problems/search-a-2d-matrix/description/
 *
 * algorithms
 * Medium (35.93%)
 * Likes:    1880
 * Dislikes: 161
 * Total Accepted:    332.8K
 * Total Submissions: 912.2K
 * Testcase Example:  '[[1,3,5,7],[10,11,16,20],[23,30,34,50]]\n3'
 *
 * Write an efficient algorithm that searches for a value in an m x n matrix.
 * This matrix has the following properties:
 * 
 * 
 * Integers in each row are sorted from left to right.
 * The first integer of each row is greater than the last integer of the
 * previous row.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input:
 * matrix = [
 * ⁠ [1,   3,  5,  7],
 * ⁠ [10, 11, 16, 20],
 * ⁠ [23, 30, 34, 50]
 * ]
 * target = 3
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * matrix = [
 * ⁠ [1,   3,  5,  7],
 * ⁠ [10, 11, 16, 20],
 * ⁠ [23, 30, 34, 50]
 * ]
 * target = 13
 * Output: false
 * 
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size();
        int n = matrix[0].size();
        int left = matrix[0][0];
        int right = matrix[0][0];
        int row = 0;
        for (int i = 0; i < m; i++)
        {
            left = matrix[i][0];
            if (left == target)
            {
                return true;
            }
            else if (left > target)
            {
                return false;
            }
            else
            {
                right = matrix[i][n-1];
                if (right == target)
                {
                    return true;
                }
                else if (right > target)
                {
                    row = i;
                }
            }
        }
        left = 0;
        right = n-1;
        int mid = n/2;
        while (left >= right)
        {
            if (matrix[row][mid] > target)
            {
                right = mid;
                mid = left + (right-left+1)/2;
            }
            else if (matrix[row][mid] < target)
            {
                left = mid;
                mid = left + (right-left+1)/2;
            }
            else
            {
                return true;
            }
        }
        return false;
    }
};
// @lc code=end

