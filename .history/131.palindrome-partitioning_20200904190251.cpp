/*
 * @lc app=leetcode id=131 lang=cpp
 *
 * [131] Palindrome Partitioning
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> partition(string s) {
        vector<vector<string>> output;
        vector<string> tem;
        helper(s,"", tem, output);
        return output;
    }
    void helper(string s,string pres, vector<string>& tem, vector<vector<string>>& output){
        int len = s.size();
        printf("%s,%s\n",s.c_str(),pres.c_str());
        if ((int)pres.size() != 0)
        {
            tem.push_back(pres);
        }
        if (len == 0)
        {
            output.push_back(tem);
            tem.pop_back();
            return;
        }
        if (isPalin(s))
        {
            helper("",s, tem, output);
        }
        for (int i = 1; i < len; i++)
        {
            if (isPalin(s.substr(0,i)))
            {
                helper(s.substr(i,len-i),s.substr(0,i), tem, output);
            }
            printf("%d",i);
        }
        tem.pop_back();
    }
    bool isPalin(string s){
        int len = s.size();
        for (int i = 0; i < len/2; i++)
        {
            if (s[i] != s[len-i-1])
            {
                return false;
            }
        }
        return true;
    }
};
// @lc code=end

