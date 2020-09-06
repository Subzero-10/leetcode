/*
 * @lc app=leetcode id=135 lang=cpp
 *
 * [135] Candy
 */
// @lc code=start
class Solution {
public:
    int candy(vector<int>& ratings) {
        int len = ratings.size();
        vector<int> left(len);
        vector<int> right(len);
        int sum = 0;
        left[0] = 1;
        right[len-1] = 1;
        for (int i = 1; i < len; i++)
        {
            if (ratings[i]>ratings[i-1])
            {
                left[i] = left[i-1]+1;
            }
            if (ratings[len-i-1]>ratings[len-i])
            {
                right[len-i-1] = right[len-i]+1;
            }
        }
        for (int i = 1; i < len; i++)
        {
            sum = max(left[i],right[i]);
        }
        return sum;
    }
};
// @lc code=end

