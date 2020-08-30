/*
 * @lc app=leetcode id=78 lang=cpp
 *
 * [78] Subsets
 *
 * https://leetcode.com/problems/subsets/description/
 *
 * algorithms
 * Medium (58.21%)
 * Likes:    4044
 * Dislikes: 86
 * Total Accepted:    606.5K
 * Total Submissions: 978.7K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a set of distinct integers, nums, return all possible subsets (the
 * power set).
 * 
 * Note: The solution set must not contain duplicate subsets.
 * 
 * Example:
 * 
 * 
 * Input: nums = [1,2,3]
 * Output:
 * [
 * ⁠ [3],
 * [1],
 * [2],
 * [1,2,3],
 * [1,3],
 * [2,3],
 * [1,2],
 * []
 * ]
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> output;
        int pos = 0;
        vector<int> tem0;
        output.push_back(tem0);
        for (int k = 1; k <= nums.size(); k++)
        {
            vector<int> tem(k,0);
            nextpos(output, tem, pos, nums.size(), k, 0, nums);
        }
        return output;
    }
    void nextpos(vector<vector<int>> &output, vector<int>& tem, int pos, int n, int k, int i, vector<int>& nums)
    {
        if (pos==(k-1))
        {
            for (; i < n-(k-pos)+1; i++)
            {
                tem[pos] = nums[i];
                output.push_back(tem);
            }
        }
        else
        {
            for (; i < n-(k-pos)+1; i++)
            {
                tem[pos] = nums[i];
                nextpos(output, tem, pos+1, nums.size(), k, i+1, nums);
            }
        }
    }
};
// @lc code=end

