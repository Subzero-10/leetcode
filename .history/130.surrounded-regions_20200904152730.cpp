/*
 * @lc app=leetcode id=130 lang=cpp
 *
 * [130] Surrounded Regions
 */

// @lc code=start
class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int len = board.size();
        if (len == 0)
        {
            return;
        }
        len = board[0].size();
        if (len == 0)
        {
            return;
        }
        vector<char> tem(len,'X');
        vector<vector<char>> m(len, tem);
        for (int i = 0; i < len; i++)
        {
            if (board[0][i] == 'O')
            {
                if (m[0][i] == 'X')
                {
                    helper(0, i, board, m);
                }
            }
        }
        for (int i = 1; i < len; i++)
        {
            printf("%d",i);
            if (board[i][0] == 'O')
            {
                if (m[i][0] == 'X')
                {
                    helper(i, 0, board, m);
                }
            }
        }
        for (int i = 1; i < len; i++)
        {
            if (board[i][len-1] == 'O')
            {
                if (m[i][len-1] == 'X')
                {
                    helper(i, len-1, board, m);
                }
            }
        }
        for (int i = 1; i < len-1; i++)
        {
            if (board[len-1][i] == 'O')
            {
                if (m[len-1][i] == 'X')
                {
                    helper(len-1, i, board, m);
                }
            }
        }
        board.assign(m.begin(), m.end());
    }
    void helper(int r, int c, vector<vector<char>>& board, vector<vector<char>>& m){
        if (r==(int)m.size() || c==(int)m.size() || r==-1 || c==-1)
        {
            return;
        }
        if (board[r][c] == 'O')
        {
            if (m[r][c] == 'X')
            {
                m[r][c] = 'O';
                printf("?");
                helper(r+1, c, board, m);
                printf("?");
                helper(r-1, c, board, m);
                helper(r, c+1, board, m);
                helper(r, c-1, board, m);
            }
        }
    }
};
// @lc code=end

