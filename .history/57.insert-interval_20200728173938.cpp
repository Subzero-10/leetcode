/*
 * @lc app=leetcode id=57 lang=cpp
 *
 * [57] Insert Interval
 *
 * https://leetcode.com/problems/insert-interval/description/
 *
 * algorithms
 * Hard (32.65%)
 * Likes:    1657
 * Dislikes: 185
 * Total Accepted:    254.2K
 * Total Submissions: 759.8K
 * Testcase Example:  '[[1,3],[6,9]]\n[2,5]'
 *
 * Given a set of non-overlapping intervals, insert a new interval into the
 * intervals (merge if necessary).
 * 
 * You may assume that the intervals were initially sorted according to their
 * start times.
 * 
 * Example 1:
 * 
 * 
 * Input: intervals = [[1,3],[6,9]], newInterval = [2,5]
 * Output: [[1,5],[6,9]]
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: intervals = [[1,2],[3,5],[6,7],[8,10],[12,16]], newInterval = [4,8]
 * Output: [[1,2],[3,10],[12,16]]
 * Explanation: Because the new interval [4,8] overlaps with
 * [3,5],[6,7],[8,10].
 * 
 * NOTE: input types have been changed on April 15, 2019. Please reset to
 * default code definition to get new method signature.
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        int situation = 0;//0:new interval; 1:connect; 2:include; 3:end
        int len = intervals.size();
        int newleft = newInterval[0];
        int newright = newInterval[1];
        int lastpos = 0;
        if (newright<intervals[0][0])
        {
            intervals.insert(intervals.begin(), newInterval);
        }
        for (int i = 0; i < len; i++)
        {
            int nowleft = intervals[i][0];
            int nowright = intervals[i][1];
            if (nowleft<=newleft && nowright>=newright)
            {
                situation = 3;
                break;
            }
            
            if (newleft>nowright)
            {
                situation = 0;
                continue;
            }
            else if (newleft<=nowright && newleft>=nowleft)
            {
                situation = 1;
                lastpos = i;
                continue;
            }
            if (situation == 0 && newleft<=nowleft)
            {
                lastpos = i;
                if (newright<nowleft)
                {
                    intervals.insert(intervals.begin()+i, newInterval);
                    situation = 3;
                    break;
                }
                if (newright>=nowleft&&newright<=nowright)
                {
                    intervals[i][0] = newInterval[0];
                    situation = 3;
                    break;
                }
                if (newright<nowleft)
                {
                    intervals[i][0] = newInterval[0];
                    intervals[i][1] = newInterval[1];
                    situation = 3;
                    break;
                }
                situation = 2;
            }
            if (situation == 2)
            {
                if (newright>=nowleft&&newright<=nowright)
                {
                    intervals[i][0] = newInterval[0];
                    intervals.erase(intervals.begin()+lastpos+1,intervals.begin()+i);
                    situation = 3;
                    break;
                }
                if (newright<nowleft)
                {
                    intervals[i-1][0] = newInterval[0];
                    intervals[i-1][1] = newInterval[1];
                    intervals.erase(intervals.begin()+lastpos+1,intervals.begin()+i-1);
                    situation = 3;
                    break;
                }
            }
            if (situation == 1)
            {
                if (newright<nowleft)
                {
                    if ((i-1)==lastpos)
                    {
                        intervals[lastpos][1] = newInterval[1];
                        situation = 3;
                        break;
                    }
                    else
                    {
                        intervals[lastpos][1] = newInterval[1];
                        intervals.erase(intervals.begin()+lastpos+1,intervals.begin()+i);
                        situation = 3;
                        break;
                    }
                }
                if (newright>=nowleft && newright<=nowright)
                {
                    intervals[i][0] = intervals[lastpos][0];
                    intervals.erase(intervals.begin()+lastpos,intervals.begin()+i);
                    situation = 3;
                    break;
                }
            }
        }
        switch (situation)
        {
        case 0:
            intervals.push_back(newInterval);
            break;

        case 1:
            intervals[len-1][1] = newright;
            break;

        case 2:
            intervals[len-1][1] = newInterval[1];
            intervals[len-1][0] = newInterval[0];
            intervals.erase(intervals.begin()+lastpos+1,intervals.end()-1);
            break;
        
        case 3:
            return intervals;
            break;

        default:
            break;
        }
        return intervals;
    }
};
// @lc code=end

