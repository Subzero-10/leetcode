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
            map<pair<int,int>,int> m;
            int imax = 0;
            int offset = 1;
            for (int j = i+1; j < len; j++)
            {
                if (points[j][1]==points[i][1]&&points[j][0]==points[i][0])
                {
                    offset++;
                    continue;
                }
                int x = points[j][0]-points[i][0];
                int y = points[j][1]-points[i][1];
                int d = gcd(x,y);
                m[pair<int,int>(x/d,y/d)]++;
                imax = max(imax,m[pair<int,int>(x/d,y/d)]);
            }
            imax += offset;
            maxnum = max(maxnum,imax);
        }
        return maxnum;
    }
    int gcd(int x, int y)
    {
        return y==0 ? x:gcd(y, x%y);
    }
};
// @lc code=end

