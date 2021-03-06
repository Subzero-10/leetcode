/*
 * @lc app=leetcode id=42 lang=cpp
 *
 * [42] Trapping Rain Water
 *
 * https://leetcode.com/problems/trapping-rain-water/description/
 *
 * algorithms
 * Hard (47.00%)
 * Likes:    7133
 * Dislikes: 122
 * Total Accepted:    516K
 * Total Submissions: 1.1M
 * Testcase Example:  '[0,1,0,2,1,0,1,3,2,1,2,1]'
 *
 * Given n non-negative integers representing an elevation map where the width
 * of each bar is 1, compute how much water it is able to trap after raining.
 * 
 * 
 * The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1].
 * In this case, 6 units of rain water (blue section) are being trapped. Thanks
 * Marcos for contributing this image!
 * 
 * Example:
 * 
 * 
 * Input: [0,1,0,2,1,0,1,3,2,1,2,1]
 * Output: 6
 * 
 */

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        int len = (int)height.size();
        if (len<3)
        {
            return 0;
        }
        
        int left = 1;
        int right = len-2;
        int maxLeft = height[0];
        int maxRight = height[len-1];
        int water = 0;
        for (int i = 1; i < len-1; i++)
        {
            if (maxLeft < maxRight)
            {
                if (height[left] < maxLeft)
                {
                    water = water + maxLeft - height[left];
                }
                else
                {
                    maxLeft = height[left];
                }
                left++;
            }
            else
            {
                if (height[right] < maxRight)
                {
                    water = water + maxRight - height[right];
                }
                else
                {
                    maxRight = height[right];
                }
                right--;
            }
        }
        return water;
    }
};
// @lc code=end

