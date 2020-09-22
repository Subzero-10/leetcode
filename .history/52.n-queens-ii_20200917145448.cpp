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

// @lc code=starth>
class Solution {
public:
    int helper(int step, int n, vector<vector<int>>& b){
        int sum = 0;
        for(int j = 0; j<n; j++){
            bool canPut = true;
            for(int k = 0; k< b.size(); k++){
                if(j == b[k][1] || abs(step-b[k][0]) == abs(j-b[k][1]))
                {
                    canPut = false;
                }
            }
            if(canPut){
                if(step == n-1)
                {
                    sum++;
                }
                else{
                    b.push_back({step,j});
                    sum += helper(step+1, n, b);
                    b.pop_back();
                }
            }
        }
        return sum;
    }
    int totalNQueens(int n) {
        vector<vector<int>> b;
        int sum = 0;
        sum += helper(0, n, b);
        return sum;
    }
};
// @lc code=end

