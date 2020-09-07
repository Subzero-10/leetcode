/*
 * @lc app=leetcode id=137 lang=cpp
 *
 * [137] Single Number II
 */

// @lc code=start
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unorderes_set<int> st;
        for (auto i:nums)
        {
            if (st.count(i))
            {
                st.erase(i);
            }
            else
            {
                st.insert(i);
            }
        }
        return *st.begin();
    }
};
// @lc code=end

