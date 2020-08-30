/*
 * @lc app=leetcode id=36 lang=cpp
 *
 * [36] Valid Sudoku
 *
 * https://leetcode.com/problems/valid-sudoku/description/
 *
 * algorithms
 * Medium (46.87%)
 * Likes:    1607
 * Dislikes: 442
 * Total Accepted:    358.3K
 * Total Submissions: 742.1K
 * Testcase Example:  '[["5","3",".",".","7",".",".",".","."],["6",".",".","1","9","5",".",".","."],[".","9","8",".",".",".",".","6","."],["8",".",".",".","6",".",".",".","3"],["4",".",".","8",".","3",".",".","1"],["7",".",".",".","2",".",".",".","6"],[".","6",".",".",".",".","2","8","."],[".",".",".","4","1","9",".",".","5"],[".",".",".",".","8",".",".","7","9"]]'
 *
 * Determine if a 9x9 Sudoku board is valid. Only the filled cells need to be
 * validated according to the following rules:
 * 
 * 
 * Each row must contain the digits 1-9 without repetition.
 * Each column must contain the digits 1-9 without repetition.
 * Each of the 9 3x3 sub-boxes of the grid must contain the digits 1-9 without
 * repetition.
 * 
 * 
 * 
 * A partially filled sudoku which is valid.
 * 
 * The Sudoku board could be partially filled, where empty cells are filled
 * with the character '.'.
 * 
 * Example 1:
 * 
 * 
 * Input:
 * [
 * ⁠ ["5","3",".",".","7",".",".",".","."],
 * ⁠ ["6",".",".","1","9","5",".",".","."],
 * ⁠ [".","9","8",".",".",".",".","6","."],
 * ⁠ ["8",".",".",".","6",".",".",".","3"],
 * ⁠ ["4",".",".","8",".","3",".",".","1"],
 * ⁠ ["7",".",".",".","2",".",".",".","6"],
 * ⁠ [".","6",".",".",".",".","2","8","."],
 * ⁠ [".",".",".","4","1","9",".",".","5"],
 * ⁠ [".",".",".",".","8",".",".","7","9"]
 * ]
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * [
 * ["8","3",".",".","7",".",".",".","."],
 * ["6",".",".","1","9","5",".",".","."],
 * [".","9","8",".",".",".",".","6","."],
 * ["8",".",".",".","6",".",".",".","3"],
 * ["4",".",".","8",".","3",".",".","1"],
 * ["7",".",".",".","2",".",".",".","6"],
 * [".","6",".",".",".",".","2","8","."],
 * [".",".",".","4","1","9",".",".","5"],
 * [".",".",".",".","8",".",".","7","9"]
 * ]
 * Output: false
 * Explanation: Same as Example 1, except with the 5 in the top left corner
 * being 
 * ⁠   modified to 8. Since there are two 8's in the top left 3x3 sub-box, it
 * is invalid.
 * 
 * 
 * Note:
 * 
 * 
 * A Sudoku board (partially filled) could be valid but is not necessarily
 * solvable.
 * Only the filled cells need to be validated according to the mentioned
 * rules.
 * The given board contain only digits 1-9 and the character '.'.
 * The given board size is always 9x9.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        map<char,int> rowNums[9];
        map<char,int> columnNums[9];
        map<char,int> boxNums[9];
        char nowNum;
        for (int i = 0; i < 9; i++)
        {
            for (int p = 0; p < 9; p++)
            {
                nowNum = board[i][p];
                if (nowNum == ',')
                {
                    continue;
                }
                else
                {
                    map<char,int>::iterator iterR = rowNums[i].find(nowNum);
                    map<char,int>::iterator iterC = columnNums[p].find(nowNum);
                    map<char,int>::iterator iterB = boxNums[(i/3)*3+p/3].find(nowNum);
                    if (iterR == rowNums[i].end())
                    {
                        rowNums[i].insert(map<char,int>::value_type(nowNum,1));
                    }
                    else
                    {

                        return false;
                    }
                    if (iterC == columnNums[p].end())
                    {
                        columnNums[p].insert(map<char,int>::value_type(nowNum,1));
                    }
                    else
                    {
                        
                        return false;
                    }
                    if (iterB == boxNums[(i/3)*3+p/3].end())
                    {
                        boxNums[(i/3)*3+p/3].insert(map<char,int>::value_type(nowNum,1));
                    }
                    else
                    {
                        
                        return false;
                    }
                    
                }
                
                
            }
            
        }
        return true;
    }
};
// @lc code=end

