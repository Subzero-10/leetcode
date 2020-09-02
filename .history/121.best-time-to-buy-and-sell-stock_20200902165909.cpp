/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty())
        {
            return 0;
        }
        
        int len = prices.size();
        vector<int> maxPrice(len);
        vector<int> minPrice(len);
        maxPrice[len-1] = prices[len-1];
        minPrice[0] = prices[0];
        for (int i = 1; i < len; i++)
        {
            minPrice[i] = min(minPrice[i-1], prices[i]);
            maxPrice[len-1-i] = max(maxPrice[len-i], prices[len-i]);
        }
        int output = 0;
        for (int i = 0; i < len; i++)
        {
            output = max((maxPrice[i] - minPrice[i]), output);
        }
        return output;
    }
};
// @lc code=end

