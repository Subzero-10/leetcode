/*
 * @lc app=leetcode id=122 lang=cpp
 *
 * [122] Best Time to Buy and Sell Stock II
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int output = 0;
        int len = prices.size();
        if (len<=1)
        {
            return output;
        }
        for (int i = 0; i < len-1; i++)
        {
            if (prices[i+1]>prices[i])
            {
                output += prices[i+1]-prices[i];
            }
        }
        return output;
    }
};
// @lc code=end

