/*
 * @lc app=leetcode id=154 lang=cpp
 *
 * [154] Find Minimum in Rotated Sorted Array II
 */

// @lc code=start
class Solution {
public:
    int findMin(vector<int>& nums) {
        return helper(nums,0 , (int)nums.size()-1);
    }
    int helper(vector<int>& nums,int left, int right){
        if (left == right)
        {
            return nums[left];
        }
        if (nums[left]<nums[right])
        {
            return nums[left];
        }
        int mid = (left+right)/2
        return min(helper(nums ,left, mid),helper(nums,mid+1 , right));
    }
};
// @lc code=end

