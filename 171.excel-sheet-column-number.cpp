/*
 * @lc app=leetcode id=171 lang=cpp
 *
 * [171] Excel Sheet Column Number
 */

// @lc code=start
class Solution {
public:
    int titleToNumber(string s) {
        int len = s.size();
        int sum = 0;
        for (int i = 0; i < len; i++)
        {
            sum += (s[i]-'A'+1)*(int)pow(26,(len-i-1));
        }
        return sum;
    }
};
// @lc code=end

