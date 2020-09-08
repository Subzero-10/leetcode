/*
 * @lc app=leetcode id=140 lang=cpp
 *
 * [140] Word Break II
 */

// @lc code=start
class Solution {
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,vector<string>> m;
        return helper(s, wordDict, m);
    }
    vector<string> helper(string s, vector<string>& wordDict, unordered_map<string,vector<string>>& m){
        if (m.count(s))
        {
            return m[s];
        }
        int len = s.size();
        vector<string> output;
        if (len == 0)
        {
            return {""};
        }
        for (int i = 0; i < (int)wordDict.size(); i++)
        {
            if (s.substr(0,wordDict[i].size()) == wordDict[i])
            {
                vector<string> tem = helper(s.substr(wordDict[i].size()), wordDict, m);
            }
            for (auto ts : tem)
            {
                output.push_back(wordDict[i] + (ts.empty()?"":" ") + ts);
            }
        }
        m[s] = output;
        return output;
    }
};
// @lc code=end

