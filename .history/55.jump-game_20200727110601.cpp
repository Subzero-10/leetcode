/*
 * @lc app=leetcode id=55 lang=cpp
 *
 * [55] Jump Game
 *
 * https://leetcode.com/problems/jump-game/description/
 *
 * algorithms
 * Medium (33.28%)
 * Likes:    4345
 * Dislikes: 329
 * Total Accepted:    485.4K
 * Total Submissions: 1.4M
 * Testcase Example:  '[2,3,1,1,4]'
 *
 * Given an array of non-negative integers, you are initially positioned at the
 * first index of the array.
 * 
 * Each element in the array represents your maximum jump length at that
 * position.
 * 
 * Determine if you are able to reach the last index.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: nums = [2,3,1,1,4]
 * Output: true
 * Explanation: Jump 1 step from index 0 to 1, then 3 steps to the last
 * index.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: nums = [3,2,1,0,4]
 * Output: false
 * Explanation: You will always arrive at index 3 no matter what. Its maximum
 * jump length is 0, which makes it impossible to reach the last index.
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= nums.length <= 3 * 10^4
 * 0 <= nums[i][j] <= 10^5
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int len = nums.size();
        int zeropos = len-1;
        bool solve = true;
        for (int i = len-2; i >= 0; i--)
        {
            if (nums[i] == 0)
            {
                if (solve)
                {
                    zeropos = i;
                    solve = false;
                }
            }
            else
            {
                if (!solve)
                {
                    if (i+nums[i]>zeropos)
                    {
                        solve = true;
                    }
                }
            }
        }
        return solve;
    }
};
// @lc code=end
