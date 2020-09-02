/*
 * @lc app=leetcode id=123 lang=cpp
 *
 * [123] Best Time to Buy and Sell Stock III
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxp = 0;
        int len = prices.size();
        for (int i = 0; i < len; i++)
        {
            vector<int> prices1(prices.begin(), prices.begin()+i);
            vector<int> prices2(prices.begin()+i, prices.end());
            maxp = max(maxp, maxProfit2(prices1)+maxProfit2(prices2));
        }
        return maxp;
    }
    int maxProfit2(vector<int>& prices) {
        int len = prices.size();
        if (len<=1)
        {
            return 0;
        }
        int sum = -1;
        int maxp = 0;
        vector<int> dis(len-1);
        for (int i = 1; i < len; i++)
        {
            dis[i-1] = prices[i] - prices[i-1];
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
            maxp = max(maxp,sum);
        }
        return maxp;
    }
};
// @lc code=end

