/*
 * @lc app=leetcode id=134 lang=cpp
 *
 * [134] Gas Station
 */

// @lc code=start
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int len = gas.size();
        vector<int> earn(len);
        for (int i = 0; i < len; i++)
        {
            earn[i] = gas[i] - cost[i];
        }
        vector<int> earn2(earn);
        earn.insert(earn.end(), earn2.begin(), earn2.end());
        int begin = 0;
        int end = 0;
        int maxe = 0;
        int sum = 0;
        int sum2 = 0;
        for (int i = 0; i < len*2; i++)
        {
            if (sum<0 && earn[i]>=0)
            {
                begin = i;
                end = i;
                sum = earn[i];
            }
            else
            {
                sum += earn[i];
                if (sum > maxe)
                {
                    end = i;
                }
            }
            if (i == begin+len)
            {
                break;
            }
            sum2 += earn[i];
        }
        if (sum2>=0)
        {
            return begin;
        }
        else
        {
            return -1;
        }
    }
};
// @lc code=end

