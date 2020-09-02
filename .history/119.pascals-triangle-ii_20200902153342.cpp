/*
 * @lc app=leetcode id=119 lang=cpp
 *
 * [119] Pascal's Triangle II
 */

// @lc code=start
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        int pre;
        vector<int> cur;
        for (int i = 0; i < rowIndex+1; i++)
        {
            for (int j = 0; j < i+1; j++)
            {
                if (j == i)
                {
                    cur.push_back(1);
                }
                else if (j == 0)
                {
                    pre = 1;
                }
                else
                {
                    int tem = cur[j];
                    cur[j] = pre + cur[j];
                    pre = tem;
                }
            }
        }
        return cur;
    }
};
// @lc code=end

