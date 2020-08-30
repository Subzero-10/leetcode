/*
 * @lc app=leetcode id=41 lang=cpp
 *
 * [41] First Missing Positive
 *
 * https://leetcode.com/problems/first-missing-positive/description/
 *
 * algorithms
 * Hard (30.87%)
 * Likes:    3476
 * Dislikes: 795
 * Total Accepted:    335.8K
 * Total Submissions: 1.1M
 * Testcase Example:  '[1,2,0]'
 *
 * Given an unsorted integer array, find the smallest missing positive
 * integer.
 * 
 * Example 1:
 * 
 * 
 * Input: [1,2,0]
 * Output: 3
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [3,4,-1,1]
 * Output: 2
 * 
 * 
 * Example 3:
 * 
 * 
 * Input: [7,8,9,11,12]
 * Output: 1
 * 
 * 
 * Note:
 * 
 * Your algorithm should run in O(n) time and uses constant extra space.
 * 
 */

// @lc code=start
class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int len = (int)nums.size();
        for (int i = 0; i < len; i++)
        {
            while (nums[i]>0 && nums[i]<=len && nums[i]!=nums[nums[i]-1])
            {
                swap(nums[i], nums[nums[i]-1])
            }
        }
        for (int i = 0; i < len; i++)
        {
            if (nums[i]!=i+1)
            {
                return i+1;
            }
        }
        return len+1;
    }
};
// @lc code=end

