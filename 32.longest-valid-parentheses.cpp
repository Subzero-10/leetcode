/*
 * @lc app=leetcode id=32 lang=cpp
 *
 * [32] Longest Valid Parentheses
 *
 * https://leetcode.com/problems/longest-valid-parentheses/description/
 *
 * algorithms
 * Hard (27.41%)
 * Likes:    3269
 * Dislikes: 131
 * Total Accepted:    275.3K
 * Total Submissions: 986.2K
 * Testcase Example:  '"(()"'
 *
 * Given a string containing just the characters '(' and ')', find the length
 * of the longest valid (well-formed) parentheses substring.
 * 
 * Example 1:
 * 
 * 
 * Input: "(()"
 * Output: 2
 * Explanation: The longest valid parentheses substring is "()"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: ")()())"
 * Output: 4
 * Explanation: The longest valid parentheses substring is "()()"
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int longestValidParentheses(string s) {
        int len = s.length();
        int num = 0;
        int last = 0;
        vector<int> que;
        vector<int> que2;
        for (int i = 0; i < len; i++)
        {
            if (s[i] == '(')
            {
                que.push_back(i);
            }
            else
            {
                if (!que.empty())
                {
                    que.pop_back();
                }
                else
                {
                    que2.push_back(i);
                }
            }
        }      
        que.insert(que.end(),que2.begin(),que2.end());
        if (que.empty())
        {
            return len;
        }
        if (que.size()==1)
        {
            return que[0]>len-que[0]-1 ? que[0] : (len-que[0]-1);
        }
        
        sort(que.begin(),que.end());
        last = que[0];
        num = last;
        for (int i = 1; i < (int)que.size(); i++)
        {
            if (que[i] - last >= num)
            {
                num = que[i] - last - 1;
            }
            last = que[i];
        }
        return len - last - 1 > num ? len - last - 1: num;
    }
};
// @lc code=end

