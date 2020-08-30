/*
 * @lc app=leetcode id=53 lang=cpp
 *
 * [53] Maximum Subarray
 *
 * https://leetcode.com/problems/maximum-subarray/description/
 *
 * algorithms
 * Easy (45.76%)
 * Likes:    8116
 * Dislikes: 384
 * Total Accepted:    1M
 * Total Submissions: 2.3M
 * Testcase Example:  '[-2,1,-3,4,-1,2,1,-5,4]'
 *
 * Given an integer array nums, find the contiguous subarray (containing at
 * least one number) which has the largest sum and return its sum.
 * 
 * Example:
 * 
 * 
 * Input: [-2,1,-3,4,-1,2,1,-5,4],
 * Output: 6
 * Explanation: [4,-1,2,1] has the largest sum = 6.
 * 
 * 
 * Follow up:
 * 
 * If you have figured out the O(n) solution, try coding another solution using
 * the divide and conquer approach, which is more subtle.
 * 
 */

// @lc code=start
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int len = nums.size();
        int sum = nums[0];
        int max = sum;
        for (int i = 1; i < len; i++)
        {
            if (nums[i]>=sum&&sum<0)
            {
                sum = nums[i];
            }
            else
            {
                sum += nums[i];
            }
            if (sum>max)
            {
                max = sum;
            }
        }
        return max;
    }
};
// @lc code=end

