/*
 * @lc app=leetcode id=179 lang=cpp
 *
 * [179] Largest Number
 */

// @lc code=start
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end(),[](int a,int b){
            return to_string(a)+to_string(b) > to_string(b)+to_string(a);
        });
        string res;
        for (int i = 0; i < (int)nums.size(); i++)
        {
            res += to_string(nums[i]);
        }
        return res[0]=='0' ? "0" : res;
    }
};
// @lc code=end

