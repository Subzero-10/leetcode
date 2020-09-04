/*
 * @lc app=leetcode id=130 lang=cpp
 *
 * [130] Surrounded Regions
 */

// @lc code=start
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int rlen = board.size();
        if (rlen == 0)
        {
            return;
        }
        int clen = board[0].size();
        if (clen == 0)
        {
            return;
        }
        vector<char> tem(clen,'X');
        vector<vector<char>> m(rlen, tem);
        for (int i = 0; i < clen; i++)
        {
            if (board[0][i] == 'O')
            {
                if (m[0][i] == 'X')
                {
                    helper(0, i, board, m);
                }
            }
        }
        for (int i = 1; i < rlen; i++)
        {
            if (board[i][0] == 'O')
            {
                if (m[i][0] == 'X')
                {
                    helper(i, 0, board, m);
                }
            }
        }
        for (int i = 1; i < rlen; i++)
        {
            if (board[i][clen-1] == 'O')
            {
                if (m[i][clen-1] == 'X')
                {
                    helper(i, clen-1, board, m);
                }
            }
        }
        for (int i = 1; i < clen-1; i++)
        {
            if (board[rlen-1][i] == 'O')
            {
                if (m[rlen-1][i] == 'X')
                {
                    helper(rlen-1, i, board, m);
                }
            }
        }
        board.assign(m.begin(), m.end());
    }
    void helper(int r, int c, vector<vector<char>>& board, vector<vector<char>>& m){
        if (r==(int)m.size() || c==(int)m[0].size() || r==-1 || c==-1)
        {
            return;
        }
        if (board[r][c] == 'O')
        {
            if (m[r][c] == 'X')
            {
                m[r][c] = 'O';
                helper(r+1, c, board, m);
                helper(r-1, c, board, m);
                helper(r, c+1, board, m);
                helper(r, c-1, board, m);
            }
        }
    }
};
// @lc code=end

