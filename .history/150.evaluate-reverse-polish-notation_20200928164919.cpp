/*
 * @lc app=leetcode id=150 lang=cpp
 *
 * [150] Evaluate Reverse Polish Notation
 */

// @lc code=start
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        s.push(0);
        int len = tokens.size();
        for (int i = 0; i < len; i++)
        {
            if (tokens[i][0] == '+')
            {
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                s.push(a+b);
            }
            else if (tokens[i][0] == '-'&&tokens[i].size()>1)
            {
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                s.push(b-a);
            }
            else if (tokens[i][0] == '/')
            {
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                s.push(b/a);
            }
            else if (tokens[i][0] == '*')
            {
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                s.push(b*a);
            }
            else
            {
                istringstream iss(tokens[i]);
                int c;
                iss>>c;
                s.push(c);
            }
        }
        return s.top();
    }
};
// @lc code=end

