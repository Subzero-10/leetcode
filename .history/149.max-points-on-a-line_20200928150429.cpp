/*
 * @lc app=leetcode id=149 lang=cpp
 *
 * [149] Max Points on a Line
 */

// @lc code=start
class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        if (points.empty() || points[0].empty())
        {
            return 0;
        }
        
        int len = points.size();
        int maxnum = 1;
        for (int i = 0; i < len; i++)
        {
            unordered_map<float,int> m;
            for (int j = i+1; j < len; j++)
            {
                float xielv;
                if (points[j][1]==points[i][1])
                {
                    xielv = -1;
                }
                else
                {
                    xielv = (points[j][0]-points[i][0])/(points[j][1]-points[i][1]);
                }
                m[xielv]++;
                maxnum = max(maxnum,m[xielv]+1);
            }
        }
        return maxnum;
    }
};
// @lc code=end

