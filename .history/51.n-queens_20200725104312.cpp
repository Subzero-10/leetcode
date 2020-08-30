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
        string queen(n,'Q');
        vector<string> chessboard(n,queen);
        vector<vector<string>> output;
        for (int j = 0; j < n; j++)
        {
            vector<string> chessboardtem(chessboard);
            haveQ(0,j,n, chessboardtem);
            output.push_back(chessboardtem);
            printf("j:%d\n",j);
        }
        return output;
    }
    bool haveQ(int i, int j, int n, vector<string>& chessboardtem)
    {
        string dot(n,'.');
        if (i==n)
        {
            return true;
        }
        
        if (chessboardtem[i] == dot)
        {
            return false;
        }
        else
        {
            for (i; i < n; i++)
            {
                for (j; j < n; j++)
                {
                    
                    vector<string> chessboardtem1(chessboardtem);
                    if (chessboardtem[i][j] == 'Q')
                    {
                        modifyBoard(i, j, n, chessboardtem1);
                    }
                    else
                    {
                        continue;
                    }
                    printf("%d\n",j);
                    if (haveQ(i+1,0,n,chessboardtem1))
                    {
                        chessboardtem.assign(chessboardtem1.begin(),chessboardtem1.end());
                        return true;
                    }
                }
            }
            return true;
        }
    }
    void modifyBoard(int i, int j, int n, vector<string>& chessboardtem)
    {
        for (int k = 0; k < n; k++)
        {
            chessboardtem[k][j] = '.';
            chessboardtem[i][k] = '.';
            if (i-k>=0&&j-k>=0)
            {
                chessboardtem[i-k][j-k] = '.';
            }
            if (i-k>=0&&j+k<n)
            {
                chessboardtem[i-k][j+k] = '.';
            }
            if (i+k<n&&j+k<n)
            {
                chessboardtem[i+k][j+k] = '.';
            }
            if (i+k<n&&j-k>=0)
            {
                chessboardtem[i+k][j-k] = '.';
            }
        }
        chessboardtem[i][j] = 'Q';
    }
};
// @lc code=end

