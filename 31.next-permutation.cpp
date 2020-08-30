/*
 * @lc app=leetcode id=31 lang=cpp
 *
 * [31] Next Permutation
 *
 * https://leetcode.com/problems/next-permutation/description/
 *
 * algorithms
 * Medium (31.84%)
 * Likes:    3141
 * Dislikes: 1129
 * Total Accepted:    356.1K
 * Total Submissions: 1.1M
 * Testcase Example:  '[1,2,3]'
 *
 * Implement next permutation, which rearranges numbers into the
 * lexicographically next greater permutation of numbers.
 * 
 * If such arrangement is not possible, it must rearrange it as the lowest
 * possible order (ie, sorted in ascending order).
 * 
 * The replacement must be in-place and use only constant extra memory.
 * 
 * Here are some examples. Inputs are in the left-hand column and its
 * corresponding outputs are in the right-hand column.
 * 
 * 1,2,3 → 1,3,2
 * 3,2,1 → 1,2,3
 * 1,1,5 → 1,5,1
 * 
 */

// @lc code=start
class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if (nums.size()<=1)
        {
            
        }
        else
        {
            int i = nums.size();
            int ii = i;
            int nowNum = nums[i - 2];
            int preNum = nums[i - 1];
            
            while (preNum<=nowNum && i>2)
            {
                i--;
                preNum = nowNum;
                nowNum = nums[i - 2];
            }            
            if (i==2&&preNum<=nowNum)
            {
                std::reverse(nums.begin(),nums.end());
            }
            else
            {
                int p;
                int swapNum = nums[ii - 1];
                while (swapNum<=nowNum)
                {
                    ii--;
                    swapNum = nums[ii - 1];
                }
                p = nowNum;
                nums[i - 2] = nums[ii - 1];
                nums[ii - 1] = p;
                std::reverse(nums.begin() + i -1,nums.end());
            }
        }
    }
};
// @lc code=end

