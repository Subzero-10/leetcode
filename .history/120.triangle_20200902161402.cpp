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
        int next = 0;
        for (int i = 0; i < (int)triangle.size(); i++)
        {
            for (int j = 0; j < i+1; j++)
            {
                if (j == i)
                {
                    dis.push_back(next + triangle[i][j]);
                    if (j != 0)
                    {
                        dis[j] = min(dis[j], next + triangle[i][j]);
                    }
                }
                if (j==0)
                {
                    dis[j] += triangle[i][j];
                    int tem = dis[j+1];
                    dis[j+1] = next + triangle[i][j+1];
                    next = tem;
                }
                else
                {
                    dis[j] = min(dis[j], next +triangle[i][j]);
                    int tem = dis[j+1];
                    dis[j+1] = next + triangle[i][j+1];
                    next = tem;
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

