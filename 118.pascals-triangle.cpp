/*
 * @lc app=leetcode id=118 lang=cpp
 *
 * [118] Pascal's Triangle
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        int pre;
        vector<int> cur;
        vector<vector<int>> output;
        for (int i = 0; i < numRows; i++)
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
            output.push_back(cur);
        }
        return output;
    }
};
// @lc code=end

