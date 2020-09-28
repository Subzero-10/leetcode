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
            unordered_map<double,int> m;
            int imax = 0;
            int offset = 1;
            int horiz = 0;
            for (int j = i+1; j < len; j++)
            {
                if (points[j][1]==points[i][1])
                {
                    if (points[j][0]==points[i][0])
                    {
                        offset++;
                    }
                    else
                    {
                        horiz++;
                    }
                    continue;
                }
                float xielv = (double)(points[j][0]-points[i][0])/(double)(points[j][1]-points[i][1]);
                printf("%f\n",xielv);
                m[xielv]++;
                imax = max(imax,m[xielv]);
            }
            imax = max(imax,horiz);
            imax += offset;
            maxnum = max(maxnum,imax);
        }
        return maxnum;
    }
};
// @lc code=end

