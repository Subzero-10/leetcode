/*
 * @lc app=leetcode id=215 lang=cpp
 *
 * [215] Kth Largest Element in an Array
 */

// @lc code=start
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int> > q;
        int maxnum = INT_MIN;
        for (int i = 0; i < k; i++)
        {
            q.push(nums[i]);
            maxnum = max(maxnum,nums[i]);
        }
        for (int i = k; i < nums.size(); i++)
        {
            if (nums[i] >= maxnum)
            {
                maxnum = nums[i];
                q.push(nums[i]);
                q.pop();
            }
        }
        for (int i = 0; i < k-1; i++)
        {
            q.pop();
        }
        return q.top();
    }
};
// @lc code=end

