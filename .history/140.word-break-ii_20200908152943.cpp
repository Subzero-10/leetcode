/*
 * @lc app=leetcode id=140 lang=cpp
 *
 * [140] Word Break II
 */

// @lc code=start
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        map<int,unordered_set<string>> m;
        for (int i = 0; i < (int)wordDict.size(); i++)
        {
            m[(int)wordDict[i].size()].insert(wordDict[i]);
        }
        vector<string> output;
        string tem;
        helper(s, m, output, tem);
        return output;
    }
    void helper(string s, map<int,unordered_set<string>>& m, vector<string> output, string tem){
        int len = s.size();
        int tlen = tem.size();
        map<int,unordered_set<string>>::iterator it;
        for (it = m.begin(); it != m.end(); it++)
        {
            if (it->first > len)
            {
                continue;
            }
            else if (it->first == len)
            {
                if (m[it->first].count(s.substr(0,it->first)))
                {
                    tem += s.substr(0,it->first);
                    output.push_back(tem);
                    printf("%s", output[0].c_str());
                    if (tlen == 0)
                    {
                        tem = "";
                    }
                    else
                    {
                        tem = tem.substr(0,tlen);
                    }
                }
            }
            else
            {
                if (m[it->first].count(s.substr(0,it->first)))
                {
                    printf("?");
                    tem += s.substr(0,it->first);
                    tem += " ";
                    helper(s.substr(it->first), m, output, tem);
                    if (tlen == 0)
                    {
                        tem = "";
                    }
                    else
                    {
                        tem = tem.substr(0,tlen);
                    }
                }
            }
        }
    }
};
// @lc code=end

