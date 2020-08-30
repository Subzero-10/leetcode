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
    int a;
    int totalNQueens(int n) {
        string queen(n,'Q');
        vector<string> chessboard(n,queen);
        haveQ(0,0,n,chessboard);
        return a;
    }
    void haveQ(int i, int j, int n, vector<string>& chessboardtem)
    {
        string dot(n,'.');
        if (i==n)
        {
            a++
            return ;
        }
        
        if (chessboardtem[i] == dot)
        {
            return ;
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
                    haveQ(i+1,0,n,chessboardtem1);
                }
                return ;
            }
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

