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
        int maxnum = 0;
        for (int i = 0; i < len; i++)
        {
            unordered_map<float,int> m;
            int imax = 0;
            int pianyi = 1;
            for (int j = i+1; j < len; j++)
            {
                float xielv;
                if (points[j][1]==points[i][1])
                {
                    if (points[j][0]==points[i][0])
                    {
                        pianyi++;
                        continue;
                    }
                    else
                    {
                        xielv = -1;
                    }
                }
                else
                {
                    xielv = (points[j][0]-points[i][0])/(points[j][1]-points[i][1]);
                }
                m[xielv]++;
                imax = max(imax,m[xielv]+1);
            }
            imax += pianyi;
            maxnum = max(maxnum,imax);
        }
        return maxnum;
    }
};
// @lc code=end

