/*
 * @lc app=leetcode id=152 lang=cpp
 *
 * [152] Maximum Product Subarray
 */

// @lc code=start
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int x = nums[0];
        int n = nums[0];
        int maxnum = nums[0];
        for (int i = 1; i < (int)nums.size(); i++)
        {
            int temx = x;
            int temn = n;
            x = max(max(temx*nums[i], temn*nums[i]),nums[i]);
            n = min(min(temx*nums[i], temn*nums[i]),nums[i]);
            maxnum = max(maxnum,x);
        }
        return maxnum;
    }
};
// @lc code=end

