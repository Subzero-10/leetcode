/*
 * @lc app=leetcode id=164 lang=cpp
 *
 * [164] Maximum Gap
 */

// @lc code=start
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int maxnum = *max_element(nums.begin(),nums.end());
        int minnum = *min_element(nums.begin(),nums.end());
        int len = nums.size();
        int bucketnum = len+1;
        int interval = (maxnum-minnum)/bucketnum;
        vector<vector<int>> bt(bucketnum,{INT_MAX,INT_MIN});
        for (int i = 0; i < len; i++)
        {
            int pos = (nums[i]-minnum)/interval;
            bt[pos][0] = min(bt[pos][0],nums[i]);
            bt[pos][1] = max(bt[pos][1],nums[i]);
        }
        minnum = bt[0][0];
        maxnum = bt[0][1];
        for (int i = 1; i < bucketnum; i++)
        {
            if (bt[])
            {
                /* code */
            }
            
        }
        
    }
};
// @lc code=end

