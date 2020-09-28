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
        int len = tokens.size();
        for (int i = 0; i < len; i++)
        {
            printf("%d",i);
            int a = s.top();
            s.pop();
            int b = s.top();
            if (tokens[i][0] == '+')
            {
                s.push(a+b);
            }
            else if (tokens[i][0] == '-')
            {
                s.push(b-a);
            }
            else if (tokens[i][0] == '/')
            {
                s.push(b/a);
            }
            else if (tokens[i][0] == '*')
            {
                s.push(b*a);
            }
            else
            {
                s.push(a);
                s.push(b);
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

