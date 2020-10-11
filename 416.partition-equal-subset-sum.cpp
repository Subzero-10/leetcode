/*
 * @lc app=leetcode id=416 lang=cpp
 *
 * [416] Partition Equal Subset Sum
 */

// @lc code=start
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = accumulate(nums.begin(),nums.end(),0);
        if (sum%2 == 1)
        {
            return false;
        }
        sum /= 2;
        vector<bool> dp(sum+1,false);
        dp[0] = true;
        for (int j = 0; j < (int)nums.size(); j++)
        {
            for (int i = sum; i >=1; i--)
            {
                if (i-nums[j]>=0)
                {
                    dp[i] = dp[i] ? dp[i] : dp[i-nums[j]];
                }
            }
        }
        return dp[sum];
    }
};
// @lc code=end

