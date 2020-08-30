/*
 * @lc app=leetcode id=90 lang=cpp
 *
 * [90] Subsets II
 *
 * https://leetcode.com/problems/subsets-ii/description/
 *
 * algorithms
 * Medium (45.42%)
 * Likes:    1747
 * Dislikes: 75
 * Total Accepted:    287.5K
 * Total Submissions: 609.6K
 * Testcase Example:  '[1,2,2]'
 *
 * Given a collection of integers that might contain duplicates, nums, return
 * all possible subsets (the power set).
 * 
 * Note: The solution set must not contain duplicate subsets.
 * 
 * Example:
 * 
 * 
 * Input: [1,2,2]
 * Output:
 * [
 * ⁠ [2],
 * ⁠ [1],
 * ⁠ [1,2,2],
 * ⁠ [2,2],
 * ⁠ [1,2],
 * ⁠ []
 * ]
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        if (nums.empty()) return {};
        vector<vector<int>> tem(1);
        int lastlen = 0;
        int lastn = nums[0];
        for (int i = 0; i < nums.size(); i++)
        {
            int len = tem.size();
            int newsize = 0;
            if (lastn == nums[i])
            {
                newsize = lastlen;
            }
            lastlen = len;
            lastn = nums[i];
            for (int j = newsize; j < len; j++)
            {
                tem.push_back(tem[j]);
                tem.back().push_back(nums[i]);
            }
        }
        return tem;
    }
};
// @lc code=end

