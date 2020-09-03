/*
 * @lc app=leetcode id=123 lang=cpp
 *
 * [123] Best Time to Buy and Sell Stock III
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;
        int s1=-prices[0],s2=INT_MIN,s3=INT_MIN,s4=INT_MIN;
        for(int i=1;i<prices.size();++i) {            
            s1 = max(s1, -prices[i]); //买入价格更低的股
            s2 = max(s2, s1+prices[i]); //卖出当前股，或者不操作
            s3 = max(s3, s2-prices[i]); //第二次买入，或者不操作
            s4 = max(s4, s3+prices[i]); //第二次卖出，或者不操作
        }
        return max(0,s4);
    }
};
// @lc code=end

