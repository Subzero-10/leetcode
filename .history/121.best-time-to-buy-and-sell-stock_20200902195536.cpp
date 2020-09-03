/*
 * @lc app=leetcode id=121 lang=cpp
 *
 * [121] Best Time to Buy and Sell Stock
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;
        //进行初始化，第一天 s1 将股票买入，其他状态全部初始化为最小值
        int s1=-prices[0],s2=INT_MIN;

        for(int i=1;i<prices.size();++i) {            
            s1 = max(s1, -prices[i]); //买入价格更低的股
            s2 = max(s2, s1+prices[i]); //卖出当前股，或者不操作
        }
        return max(0,s2);
    }
};
// @lc code=end

