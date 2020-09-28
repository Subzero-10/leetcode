/*
 * @lc app=leetcode id=151 lang=cpp
 *
 * [151] Reverse Words in a String
 */

// @lc code=start
class Solution {
public:
    string reverseWords(string s) {
        string output;
        istringstream iss(s);
        stack<string> st;
        string tem;
        while (iss>>tem)
        {
            st.push(tem);
        }
        int len = st.size();
        if (len==0)
        {
            return "";
        }
        for (int i = 0; i < len-1; i++)
        {
            output += st.top();
            output += " ";
            st.pop();
        }
        output += st.top();
        return output;
    }
};
// @lc code=end

