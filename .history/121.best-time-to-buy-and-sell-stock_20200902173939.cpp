/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        int sum = -1;
        int max = 0;
        vector<int> dis(len);
        for (int i = 1; i < len; i++)
        {
            dis[i] = prices[i] - prices[i-1];
        }
        for (int i = 0; i < len-1; i++)
        {
            if (dis[i] > sum && sum < 0)
            {
                sum = dis[i];
            }
            else
            {
                sum += dis[i];
            }
            max = max(max,sum);
        }
        return max;
    }
};
// @lc code=end

