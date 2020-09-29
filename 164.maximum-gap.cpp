/*
 * @lc app=leetcode id=164 lang=cpp
 *
 * [164] Maximum Gap
 */

// @lc code=start
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int len = nums.size();
        if (len<=1)
        {
            return 0;
        }
        int maxnum = *max_element(nums.begin(),nums.end());
        int minnum = *min_element(nums.begin(),nums.end());
        int bucketnum = len+1;
        int interval = (maxnum-minnum)/bucketnum+1;
        vector<vector<int>> bt(bucketnum,{INT_MAX,INT_MIN});
        for (int i = 0; i < len; i++)
        {
            int pos = (nums[i]-minnum)/interval;
            bt[pos][0] = min(bt[pos][0],nums[i]);
            bt[pos][1] = max(bt[pos][1],nums[i]);
        }
        maxnum = bt[0][1];
        int op = 0;
        for (int i = 1; i < bucketnum; i++)
        {
            if (bt[i][0]!=INT_MAX)
            {
                op = max(op,bt[i][0] - maxnum);
                maxnum = bt[i][1];
            }
        }
        return op;
    }
};
// @lc code=end

