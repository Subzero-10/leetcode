/*
 * @lc app=leetcode id=51 lang=cpp
 *
 * [51] N-Queens
 *
 * https://leetcode.com/problems/n-queens/description/
 *
 * algorithms
 * Hard (44.01%)
 * Likes:    1920
 * Dislikes: 73
 * Total Accepted:    204.2K
 * Total Submissions: 441K
 * Testcase Example:  '4'
 *
 * The n-queens puzzle is the problem of placing n queens on an n×n chessboard
 * such that no two queens attack each other.
 * 
 * 
 * 
 * Given an integer n, return all distinct solutions to the n-queens puzzle.
 * 
 * Each solution contains a distinct board configuration of the n-queens'
 * placement, where 'Q' and '.' both indicate a queen and an empty space
 * respectively.
 * 
 * Example:
 * 
 * 
 * Input: 4
 * Output: [
 * ⁠[".Q..",  // Solution 1
 * ⁠ "...Q",
 * ⁠ "Q...",
 * ⁠ "..Q."],
 * 
 * ⁠["..Q.",  // Solution 2
 * ⁠ "Q...",
 * ⁠ "...Q",
 * ⁠ ".Q.."]
 * ]
 * Explanation: There exist two distinct solutions to the 4-queens puzzle as
 * shown above.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<int>> b;
        vector<vector<string>> output;
        vector<string> temb;
        helper(0, n, b,temb,output);
        return output;
    }
    void helper(int step, int n, vector<vector<int>>& b, vector<string>& temb,vector<vector<string>>& output){
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
                    string tems(n, '.');
                    tems[j] = 'Q';
                    temb.push_back(tems);
                    output.push_back(temb);
                    temb.pop_back();
                }
                else{
                    b.push_back({step,j});
                    string tems(n, '.');
                    tems[j] = 'Q';
                    temb.push_back(tems);
                    helper(step+1, n, b,temb,output);
                    b.pop_back();
                    temb.pop_back();
                }
            }
        }
    }
};
// @lc code=end

