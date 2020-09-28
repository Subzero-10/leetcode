/*
 * @lc app=leetcode id=152 lang=cpp
 *
 * [152] Maximum Product Subarray
 */

// @lc code=start
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int len = nums.size();
        int maxnum = INT_MIN;
        vector<int> dp(len+1,1);
        vector<int> dp0(len,1);
        int tem = 1;
        int first = -1;
        int second = -1;
        for (int i = 0; i < len; i++)
        {
            if (nums[i] > 0)
            {
                tem *= nums[i];
                dp0[i] = tem;
            }
            else if (nums[i] == 0)
            {
                dp0[i] = 0;
                tem = 1;
            }
            else
            {
                dp0[i] = tem * nums[i];
                tem = 1;
            }
        }
        for (int i = 1; i < len+1; i++)
        {
            if (dp0[i-1]>0)
            {
                if (dp[i-1]>0)
                {
                    dp[i] *= dp[i-1];
                }
                else
                {
                    dp[i] = dp0[i-1];
                }
            }
            else if (dp0[i-1]==0)
            {
                int first = -1;
                int second = -1;
                dp[i] = 0;
            }
            else
            {
                if (second == -1)
                {
                    dp[i] = dp0[i-1];
                    second = i;
                }
                else if (first == -1)
                {
                    dp[i] = dp0[i-1] * dp0[second-1];
                    first = second;
                    second = i;
                }
                else if (dp[first]>0)
                {
                    dp[i] = dp0[i-1] * dp0[second-1] * dp[first];
                    first = second;
                    second = i;
                }
                else
                {
                    dp[i] = dp0[i-1] * dp0[second-1];
                    first = second;
                    second = i;
                }
            }
            maxnum = max(dp[i],maxnum);
        }
        return maxnum;
    }
};
// @lc code=end

