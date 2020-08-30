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
        set<vector<int>> tem;
        vector<int> a;
        tem.insert(a);
        for (int i = 0; i < nums.size(); i++)
        {
            set<vector<int>>::iterator it;
            for (it = tem.begin(); it != tem.end(); it++)
            {
                a.assign(it.begin(), it.end());
                a.push_back(nums[i]);
                tem.insert(a);
            }
        }
        vector<vector<int>> output(tem.begin(), tem.end());
        return output;
    }
};
// @lc code=end

