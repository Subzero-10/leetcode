/*
 * @lc app=leetcode id=169 lang=cpp
 *
 * [169] Majority Element
 */

// @lc code=start
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int pre = nums[0];
        int sum = 1;
        int len = nums.size();
        for (int i = 1; i < len; i++)
        {
            if (nums[i] == pre)
            {
                sum++;
            }
            else
            {
                sum--;
            }
            if (sum == 0)
            {
                sum = 1;
                pre = nums[i];
            }
        }
        return pre;

    }
};
// @lc code=end

