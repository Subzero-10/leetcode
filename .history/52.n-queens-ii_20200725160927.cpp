/*
 * @lc app=leetcode id=52 lang=cpp
 *
 * [52] N-Queens II
 *
 * https://leetcode.com/problems/n-queens-ii/description/
 *
 * algorithms
 * Hard (55.76%)
 * Likes:    521
 * Dislikes: 154
 * Total Accepted:    134.9K
 * Total Submissions: 234.2K
 * Testcase Example:  '4'
 *
 * The n-queens puzzle is the problem of placing n queens on an n×n chessboard
 * such that no two queens attack each other.
 * 
 * 
 * 
 * Given an integer n, return the number of distinct solutions to the n-queens
 * puzzle.
 * 
 * Example:
 * 
 * 
 * Input: 4
 * Output: 2
 * Explanation: There are two distinct solutions to the 4-queens puzzle as
 * shown below.
 * [
 * [".Q..",  // Solution 1
 * "...Q",
 * "Q...",
 * "..Q."],
 * 
 * ["..Q.",  // Solution 2
 * "Q...",
 * "...Q",
 * ".Q.."]
 * ]
 * 
 * 
 */

// @lc code=start
class Solution {
public:
        int totalNQueens(int n) {
        int res = 0;
        vector<bool> cols(n), diag(2 * n), anti_diag(2 * n);
        helper(n, 0, cols, diag, anti_diag, res);
        return res;
    }
    void helper(int n, int row, vector<bool>& cols, vector<bool>& diag, vector<bool>& anti_diag, int& res) {
        if (row == n) ++res;
        for (int col = 0; col < n; ++col) {
            int idx1 = col - row + n, idx2 = col + row;
            if (cols[col] || diag[idx1] || anti_diag[idx2]) continue;
            cols[col] = diag[idx1] = anti_diag[idx2] = true;
            helper(n, row + 1, cols, diag, anti_diag, res);
            cols[col] = diag[idx1] = anti_diag[idx2] = false;
        }
    }
};
// @lc code=end

