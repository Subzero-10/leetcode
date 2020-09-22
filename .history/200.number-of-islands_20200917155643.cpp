/*
 * @lc app=leetcode id=200 lang=cpp
 *
 * [200] Number of Islands
 */

// @lc code=start
class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        int r = grid.size();
        if (r==0)
        {
            return 0;
        }
        int c = grid[0].size();
        if (c==0)
        {
            return 0;
        }
        vector<int> st(r*c, -1);
        for (int i = 0; i < r; i++)
        {
            for (int j = 0; j < c; j++)
            {
                if (grid[i][j] == '1')
                {
                    st[i*c+j] = i*c+j;
                    if (i>0 && grid[i-1][j] == '1')
                    {
                        comb(i*c+j, (i-1)*c+j ,st);
                    }
                    if (j>0 && grid[i][j-1] == '1')
                    {
                        comb(i*c+j-1, i*c+j ,st);
                    }
                }
            }
        }
        for (int i = 0; i < r*c; i++)
        {
            if (st[i] != -1)
            {
                find(i, st);
            }
        }
        unordered_set<int> output(st.begin(), st.end());
        if (output.count(-1))
        {
            return (output.size()-1);
        }
        return output.size();
        
    }
    int find(int a, vector<int>& st){
        int tem = a;
        while (st[tem] != tem)
        {
            tem = st[tem];
        }
        int root = tem;
        tem = a;
        while (st[tem] != tem)
        {
            int next = st[tem];
            st[tem] = root;
            tem = next;
        }
        return root;
    }
    void comb(int a, int b, vector<int>& st){
        int aa = find(a,st);
        int bb = find(b,st);
        if (aa!=bb)
        {
            st[a] = bb;
        }
    }
};
// @lc code=end

