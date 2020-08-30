/*
 * @lc app=leetcode id=45 lang=cpp
 *
 * [45] Jump Game II
 *
 * https://leetcode.com/problems/jump-game-ii/description/
 *
 * algorithms
 * Hard (29.80%)
 * Likes:    2549
 * Dislikes: 135
 * Total Accepted:    260.7K
 * Total Submissions: 856.1K
 * Testcase Example:  '[2,3,1,1,4]'
 *
 * Given an array of non-negative integers, you are initially positioned at the
 * first index of the array.
 * 
 * Each element in the array represents your maximum jump length at that
 * position.
 * 
 * Your goal is to reach the last index in the minimum number of jumps.
 * 
 * Example:
 * 
 * 
 * Input: [2,3,1,1,4]
 * Output: 2
 * Explanation: The minimum number of jumps to reach the last index is 2.
 * ⁠   Jump 1 step from index 0 to 1, then 3 steps to the last index.
 * 
 * Note:
 * 
 * You can assume that you can always reach the last index.
 * 
 */

// @lc code=start
class Solution {
public:
    int jump(vector<int>& nums) {
        int nowpos = 0;
        int nextpos = 0;
        int len = nums.size();
        int count = 1;
        if (len<2)
        {
            return 0;
        }
        if (nums[0]>=len-1)
        {
            return 1;
        }
        
        for (int i = 0; i < len; i++)
        {
            int maxdis = 0;
            nowpos = i;
            for (int j = 0; j < nums[nowpos]; j++)
            {
                if (nowpos+j+1+nums[j+1+nowpos] >= len-1)
                {
                    count++;
                    return count;
                }
                
                if (maxdis<(j+1+nums[j+1+nowpos]))
                {
                    nextpos = j+1+nowpos;
                    maxdis = j+1+nums[j+1+nowpos];
                }
            }
            count++;
            i = nextpos - 1;
        }
        return count;
        
    }
};
// @lc code=end

