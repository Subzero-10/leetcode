/*
 * @lc app=leetcode id=84 lang=cpp
 *
 * [84] Largest Rectangle in Histogram
 *
 * https://leetcode.com/problems/largest-rectangle-in-histogram/description/
 *
 * algorithms
 * Hard (33.58%)
 * Likes:    3910
 * Dislikes: 88
 * Total Accepted:    273.5K
 * Total Submissions: 776.2K
 * Testcase Example:  '[2,1,5,6,2,3]'
 *
 * Given n non-negative integers representing the histogram's bar height where
 * the width of each bar is 1, find the area of largest rectangle in the
 * histogram.
 * 
 * 
 * 
 * 
 * Above is a histogram where width of each bar is 1, given height =
 * [2,1,5,6,2,3].
 * 
 * 
 * 
 * 
 * The largest rectangle is shown in the shaded area, which has area = 10
 * unit.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Input: [2,1,5,6,2,3]
 * Output: 10
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if (heights.empty())
        {
            return 0;
        }
        stack<int> s;
        int pos = 0;
        int len = heights.size();
        int maxArea = 0;
        for (int i = 0; i < len; i++)
        {
            if (!s.empty())
            {
                while (heights[i]<heights[s.top()])
                {
                    pos = s.top();
                    s.pop();
                    if (s.empty())
                    {
                        maxArea = max(maxArea, (i-0)*heights[pos]);
                        break;
                    }
                    else
                    {
                        maxArea = max(maxArea, (i-s.top()-1)*heights[pos]);
                    }
                }
            }
            s.push(i);
        }
        while (0<heights[s.top()])
        {
            pos = s.top();
            s.pop();
            if (s.empty())
            {
                maxArea = max(maxArea, (len-0)*heights[pos]);
                break;
            }
            else
            {
                maxArea = max(maxArea, (len-s.top()-1)*heights[pos]);
            }
        }
        return maxArea;
    }
};
// @lc code=end

