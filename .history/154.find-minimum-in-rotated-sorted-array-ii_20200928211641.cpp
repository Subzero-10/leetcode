/*
 * @lc app=leetcode id=154 lang=cpp
 *
 * [154] Find Minimum in Rotated Sorted Array II
 */

// @lc code=start
class Solution {
public:
    int findMin(vector<int>& nums) {
        int len = nums.size();
        if (len==2&&nums[0]<=nums[1])
        {
            return nums[0];
        }
        int left = 0;
        int right = len-1;
        int mid;
        while (left<right-1)
        {
            mid = (left+right)/2;
            if (nums[mid] >= nums[left])
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

