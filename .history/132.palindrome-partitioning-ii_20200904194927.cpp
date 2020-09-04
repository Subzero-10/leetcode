/*
 * @lc app=leetcode id=132 lang=cpp
 *
 * [132] Palindrome Partitioning II
 */

// @lc code=start
class Solution {
public:
    int minCut(string s) {
        int len = s.size();
        if (len<=1)
        {
            return 0;
        }
        vector<bool> d(len, false);
        vector<vector<bool>> dp(len,d);
        for (int i = len-1; i >= 0; i--)
        {
            for (int j = len-1; j >= i; j--)
            {
                if (j == i)
                {
                    dp[i][j] = true;
                }
                else if (j - i <= 2)
                {
                    dp[i][j] = (s[i] == s[j]);
                }
                else
                {
                    dp[i][j] = (dp[i+1][j-1] && (s[i] == s[j]));
                }
            }
        }
        queue<int> q;
        unordered_set<int> numset;
        for (int i = 1; i < len; i++)
        {
            numset.insert(i);
        }
        q.push(0);
        int cut = 0;
        while (!q.empty())
        {
            int qlen = q.size();
            for (int i = 0; i < qlen; i++)
            {
                for (int j = q.front(); j < len; j++)
                {
                    if (dp[q.front()][j])
                    {
                        if (j==len-1)
                        {
                            return cut;
                        }
                        if (numset.count(j+1))
                        {
                            numset.erase(j+1);
                            q.push(j+1);
                        }
                    }
                    
                }
                q.pop();
            }
            cut++;
        }
        return cut;
    }
};
// @lc code=end

