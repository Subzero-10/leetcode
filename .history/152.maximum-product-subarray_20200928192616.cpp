/*
 * @lc app=leetcode id=152 lang=cpp
 *
 * [152] Maximum Product Subarray
 */

// @lc code=start
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int lastnega = -1;
        int len = nums.size();
        int maxnum = INT_MIN;
        vector<int> dp(len+1,1);
        for (int i = 1; i < len+1; i++)
        {
            if (nums[i-1] == 0)
            {
                dp[i] = 0;
                lastnega = i;
            }
            else if (nums[i-1] > 0)
            {
                if (dp[i-1] > 0)
                {
                    dp[i] = nums[i-1]*dp[i-1];
                }
                else
                {
                    dp[i] = nums[i-1];
                }
            }
            else
            {
                if (lastnega != -1)
                {
                    if (dp[lastnega] >= 0)
                    {
                        dp[i] = nums[i-1];
                    }
                    else
                    {
                        dp[i] = dp[lastnega-1] == 0 ? dp[lastnega]*dp[i-1]*nums[i-1] : dp[lastnega-1]*dp[lastnega]*dp[i-1]*nums[i-1];
                    }
                }
                else
                {
                    dp[i] = nums[i-1];
                }
                lastnega = i;
            }
            printf("%d\n", dp[i]);
            maxnum = max(maxnum,dp[i]);
        }
        return maxnum;
    }
};
// @lc code=end

