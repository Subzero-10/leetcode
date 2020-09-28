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
        iss>>output;
        string tem;
        while (iss>>tem)
        {
            output = tem + " " + output;
        }
        return output;
    }
};
// @lc code=end

