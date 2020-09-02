/*
 * @lc app=leetcode id=120 lang=cpp
 *
 * [120] Triangle
 */

// @lc code=start
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<int> dis;
        int pre = 0;
        for (int i = 0; i < (int)triangle.size(); i++)
        {
            for (int j = 0; j < i+1; j++)
            {
                if (j == i)
                {
                    dis.push_back(pre + triangle[i][j]);
                }
                else if (j==0)
                {
                    pre = dis[j];
                    dis[j] += triangle[i][j];
                }
                else
                {
                    int tem = dis[j];
                    dis[j] = min(dis[j+1] + triangle[i][j], pre + triangle[i][j]);
                    pre = tem;
                }
            }
        }
        int mt = INT_MAX;
        for (int i = 0; i < (int)dis.size(); i++)
        {
            if (dis[i]<mt)
            {
                mt = dis[i];
            }
        }
        return mt;
    }
};
// @lc code=end

