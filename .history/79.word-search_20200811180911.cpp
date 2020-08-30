/*
 * @lc app=leetcode id=79 lang=cpp
 *
 * [79] Word Search
 *
 * https://leetcode.com/problems/word-search/description/
 *
 * algorithms
 * Medium (33.77%)
 * Likes:    4082
 * Dislikes: 196
 * Total Accepted:    507.7K
 * Total Submissions: 1.4M
 * Testcase Example:  '[["A","B","C","E"],["S","F","C","S"],["A","D","E","E"]]\n"ABCCED"'
 *
 * Given a 2D board and a word, find if the word exists in the grid.
 * 
 * The word can be constructed from letters of sequentially adjacent cell,
 * where "adjacent" cells are those horizontally or vertically neighboring. The
 * same letter cell may not be used more than once.
 * 
 * Example:
 * 
 * 
 * board =
 * [
 * ⁠ ['A','B','C','E'],
 * ⁠ ['S','F','C','S'],
 * ⁠ ['A','D','E','E']
 * ]
 * 
 * Given word = "ABCCED", return true.
 * Given word = "SEE", return true.
 * Given word = "ABCB", return false.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * board and word consists only of lowercase and uppercase English letters.
 * 1 <= board.length <= 200
 * 1 <= board[i].length <= 200
 * 1 <= word.length <= 10^3
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        for (int i = 0; i < board.size(); i++)
        {
            for (int j = 0; j < board[0].size(); j++)
            {
                if (next(board, word, i, j, 0) )
                {
                    return true;
                }
            }
            
        }
        return false;
    }
    bool next(vector<vector<char>>& board, string word,int x, int y, int pos) {
        if (board[x][y] == word[pos])
        {
            board[x][y] = '0';
            if (pos == word.size()-1)
            {
                return true;
            }
            else
            {
                if (x!=0 && next(board, word, x-1, y, pos+1))
                {
                    return true;
                }
                if (x!=board.size()-1 && next(board, word, x+1, y, pos+1))
                {
                    return true;
                }
                if (y!=board[0].size()-1 && next(board, word, x, y+1, pos+1))
                {
                    return true;
                }
                if (y!=0 && next(board, word, x, y-1, pos+1))
                {
                    return true;
                }
            }
        }
        printf("%d",pos);
        board[x][y] = word[pos];
        return false;
    }
};
// @lc code=end

