/*
 * @lc app=leetcode id=56 lang=cpp
 *
 * [56] Merge Intervals
 *
 * https://leetcode.com/problems/merge-intervals/description/
 *
 * algorithms
 * Medium (38.08%)
 * Likes:    4392
 * Dislikes: 297
 * Total Accepted:    614.7K
 * Total Submissions: 1.6M
 * Testcase Example:  '[[1,3],[2,6],[8,10],[15,18]]'
 *
 * Given a collection of intervals, merge all overlapping intervals.
 * 
 * Example 1:
 * 
 * 
 * Input: [[1,3],[2,6],[8,10],[15,18]]
 * Output: [[1,6],[8,10],[15,18]]
 * Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into
 * [1,6].
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [[1,4],[4,5]]
 * Output: [[1,5]]
 * Explanation: Intervals [1,4] and [4,5] are considered overlapping.
 * 
 * NOTE: input types have been changed on April 15, 2019. Please reset to
 * default code definition to get new method signature.
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int len = intervals.size();
        bool control = true;
        for (int i = 0; i < intervals.size(); i++)
        {
            int tempi = i;
            if (control)
            {
                //swap(intervals[0],intervals[i]);
            }
            for (int j = 1; j < intervals.size(); j++)
            {
                //printf("%d,%d,%d\n",tempi,j,intervals[j][0]);
                int jleft = intervals[j][0];
                int jright = intervals[j][1];
                int ileft = intervals[tempi][0];
                int iright = intervals[tempi][1];
                if (ileft<=jleft && iright<=jright && iright>=jleft)
                {
                    intervals[tempi][1] = intervals[j][1];
                    intervals[j][0] = intervals[intervals.size()-1][0];
                    intervals[j][1] = intervals[intervals.size()-1][1];
                    intervals.pop_back();
                    j--;
                }
                else if (iright<jleft)
                {
                    continue;
                }
                else if (ileft>=jleft && iright<=jright)
                {
                    intervals[tempi][0] = intervals[j][0];
                    intervals[tempi][1] = intervals[j][1];
                    intervals[j][0] = intervals[intervals.size()-1][0];
                    intervals[j][1] = intervals[intervals.size()-1][1];
                    intervals.pop_back();
                    j--;
                }
                else if (ileft>=jleft && iright>=jright && ileft<=jright)
                {
                    intervals[tempi][0] = intervals[j][0];
                    intervals[j][0] = intervals[intervals.size()-1][0];
                    intervals[j][1] = intervals[intervals.size()-1][1];
                    intervals.pop_back();
                    j--;
                }
                else if (ileft>jright)
                {
                    continue;
                }
                else if (ileft<=jleft && iright>=jright)
                {
                    intervals[j][0] = intervals[intervals.size()-1][0];
                    intervals[j][1] = intervals[intervals.size()-1][1];
                    intervals.pop_back();
                    j--;
                }
            }
            if (len != intervals.size())
            {
                i--;
                control = false;
                len = intervals.size();
            }
            else
            {
                control = true;
            }
            
        }
        return intervals;
    }
};
// @lc code=end

