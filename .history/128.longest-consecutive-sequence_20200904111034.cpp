/*
 * @lc app=leetcode id=128 lang=cpp
 *
 * [128] Longest Consecutive Sequence
 */

// @lc code=start
class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        map<int,int> numsMap;
        int maxl = 0;
        for (int i = 0; i < (int)nums.size(); i++)
        {
            if (numsMap.count(nums[i]+1) && numsMap.count(nums[i]-1))
            {
                numsMap[nums[i]] = numsMap[nums[i]+1] + numsMap[nums[i]-1] + 1;
                numsMap[nums[i]+numsMap[nums[i]]] = numsMap[nums[i]];
                numsMap[nums[i]-numsMap[nums[i]]] = numsMap[nums[i]];
            }
            else if (numsMap.count(nums[i]+1))
            {
                numsMap[nums[i]] = numsMap[nums[i]+1] + 1;
                numsMap[nums[i]+numsMap[nums[i]]] = numsMap[nums[i]];
            }
            else if (numsMap.count(nums[i]-1))
            {
                numsMap[nums[i]] = numsMap[nums[i]-1] + 1;
                numsMap[nums[i]-numsMap[nums[i]]] = numsMap[nums[i]];
            }
            else
            {
                numsMap[nums[i]] = 1;
            }
            maxl = max(maxl,numsMap[nums[i]]);
        }
        return maxl;
    }
};
// @lc code=end

