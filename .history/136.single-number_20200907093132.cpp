/*
 * @lc app=leetcode id=136 lang=cpp
 *
 * [136] Single Number
 */

// @lc code=start
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        map<int,int> m;
        for (int i = 0; i < (int)nums.size(); i++)
        {
            if (!m.count(nums[i]))
            {
                m[nums[i]] = 1;
            }
            else
            {
                m.earse(nums[i]);
            }
        }
        map<int,int>::iterator i = m.begin();
        return *i.first();
    }
};
// @lc code=end

