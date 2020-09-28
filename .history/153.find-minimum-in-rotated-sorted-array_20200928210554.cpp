/*
 * @lc app=leetcode id=153 lang=cpp
 *
 * [153] Find Minimum in Rotated Sorted Array
 */

// @lc code=start
class Solution {
public:
    int findMin(vector<int>& nums) {
        int len = nums.size();
        if (nums[0]<=nums[len-1])
        {
            return nums[0];
        }
        int left = 0;
        int right = len-1;
        int mid;
        while (left<right-1)
        {
            mid = (left+right)/2;
            if (mid > left)
            {
                left = mid;
            }
            else
            {
                right = mid;
            }
        }
        return nums[right];
    }
};
// @lc code=end

