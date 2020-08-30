/*
 * @lc app=leetcode id=47 lang=cpp
 *
 * [47] Permutations II
 *
 * https://leetcode.com/problems/permutations-ii/description/
 *
 * algorithms
 * Medium (44.41%)
 * Likes:    1943
 * Dislikes: 61
 * Total Accepted:    353.9K
 * Total Submissions: 767.2K
 * Testcase Example:  '[1,1,2]'
 *
 * Given a collection of numbers that might contain duplicates, return all
 * possible unique permutations.
 * 
 * Example:
 * 
 * 
 * Input: [1,1,2]
 * Output:
 * [
 * ⁠ [1,1,2],
 * ⁠ [1,2,1],
 * ⁠ [2,1,1]
 * ]
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int len = nums.size();
        vector<vector<int>> output;
        set<vector<int>> temset;
        output.push_back(nums);
        for (int i = 1; i < len; i++)
        {
            int len1 = output.size();
            for (int j = 0; j < len1; j++)
            {
                for (int k = 0; k < i; k++)
                {
                    vector<int> tem = output[j];
                    swap(tem[k],tem[i]);
                    temset.insert(tem);
                }
            }
            vector<vector<int>> temout;
            temout.assign(temset.begin(), temset.end());
            output.insert(output.end(), temout.begin(), temout.end());
        }
        return output;
    }
};
// @lc code=end

