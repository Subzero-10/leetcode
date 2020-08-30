/*
 * @lc app=leetcode id=46 lang=cpp
 *
 * [46] Permutations
 *
 * https://leetcode.com/problems/permutations/description/
 *
 * algorithms
 * Medium (60.59%)
 * Likes:    3935
 * Dislikes: 105
 * Total Accepted:    613.5K
 * Total Submissions: 972.1K
 * Testcase Example:  '[1,2,3]'
 *
 * Given a collection of distinct integers, return all possible permutations.
 * 
 * Example:
 * 
 * 
 * Input: [1,2,3]
 * Output:
 * [
 * ⁠ [1,2,3],
 * ⁠ [1,3,2],
 * ⁠ [2,1,3],
 * ⁠ [2,3,1],
 * ⁠ [3,1,2],
 * ⁠ [3,2,1]
 * ]
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int len = nums.size();
        //vector<vector<int>> tem;
        vector<vector<int>> output;
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
                    output.push_back(tem);
                }
            }
        }
        return output;

    }
};
// @lc code=end

