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
        int maxHeight = 0;
        for (int i = 0; i < upper.size(); i++)
        {
            if (i==0)
            {
                int minNum = heights[i];
                for (int j = i; j < heights.size(); j++)
                {
                    minNum = min(minNum, heights[j]);
                    maxHeight = max(maxHeight,(j-i+1)*minNum);
                }
            }
            else if (heights[i-1]<heights[i])
            {
                int minNum = heights[i];
                for (int j = i; j < heights.size(); j++)
                {
                    minNum = min(minNum, heights[j]);
                    maxHeight = max(maxHeight,(j-i+1)*minNum);
                }
            }
        }
        return maxHeight;
    }
};
// @lc code=end

