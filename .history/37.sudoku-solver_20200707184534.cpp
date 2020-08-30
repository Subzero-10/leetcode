/*
 * @lc app=leetcode id=37 lang=cpp
 *
 * [37] Sudoku Solver
 *
 * https://leetcode.com/problems/sudoku-solver/description/
 *
 * algorithms
 * Hard (41.14%)
 * Likes:    1760
 * Dislikes: 91
 * Total Accepted:    184.5K
 * Total Submissions: 429.7K
 * Testcase Example:  '[["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]'
 *
 * Write a program to solve a Sudoku puzzle by filling the empty cells.
 * 
 * A sudoku solution must satisfy all of the following rules:
 * 
 * 
 * Each of the digits 1-9 must occur exactly once in each row.
 * Each of the digits 1-9 must occur exactly once in each column.
 * Each of the the digits 1-9 must occur exactly once in each of the 9 3x3
 * sub-boxes of the grid.
 * 
 * 
 * Empty cells are indicated by the character '.'.
 * 
 * 
 * A sudoku puzzle...
 * 
 * 
 * ...and its solution numbers marked in red.
 * 
 * Note:
 * 
 * 
 * The given board contain only digits 1-9 and the character '.'.
 * You may assume that the given Sudoku puzzle will have a single unique
 * solution.
 * The given board size is always 9x9.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    void solveSudoku(vector<vector<char>>& board) {
        fillNum(board, 0, 0);
        
    }
    bool fillNum(vector<vector<char>>& board, int i, int j){
        for (; i < 9; i++)
        {
            for (; j < 9; j++)
            {
                if (board[i][j] == '.')
                {
                    vector<char> candidateNum;
                    candidateNum = numCanUse(board, i, j);
                    
                    for(const int& k : candidateNum)
                            cout << k << " ";
                    cout << endl;

                    while (1)
                    {
                        if (candidateNum.empty())
                        {
                            return false;
                        }
                        else
                        {
                            printf("size:%d",candidateNum.size());
                            board[i][j] = candidateNum[candidateNum.size()-1];
                            candidateNum.pop_back();
                        }
                        if (fillNum(board, i+j/9, j+1-((j+1)/9)*9))
                        {
                            return true;
                        }
                    }
                }
                
            }
        }
        return true;
    }
    vector<char> numCanUse(vector<vector<char>>& board, int i, int j){
        char n[] = {'1', '2', '3', '4', '5', '6', '7', '8', '9'} ;
        for (int ii = 0; ii < 9; ii++)
        {
            if (board[i][ii] != '.')
            {
                n[board[i][ii] - '0' - 1] = '0';
            }
            if (board[ii][j] != '.')
            {
                n[board[ii][j] - '0' - 1] = '0';
            }
            if (board[(i/3)*3 + ii/3][j/3 + ii-(ii/3)*3] != '.')
            {
                n[board[(i/3)*3 + ii/3][j/3 + ii-(ii/3)*3] - '0' - 1] = '0';
            }
        }
        vector<char> candidateNum;
        for (int ii = 0; ii < 9; ii++)
        {
            if (n[ii] != '0')
            {
                candidateNum.push_back(n[ii]);
            }
        }
        return candidateNum;
    }
};
// @lc code=end

