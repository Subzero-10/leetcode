/*
 * @lc app=leetcode id=126 lang=cpp
 *
 * [126] Word Ladder II
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        vector<vector<string>> output;
        map<string, vector<string>> stringMap;
        unordered_set<string> wordSet(wordList.begin(), wordList.end());
        unordered_set<string> thisWord;
        queue<string> q;
        q.push(beginWord);
        bool find = false;
        while (!q.empty())
        {
            unordered_set<string>::iterator it;
            for (it = thisWord.begin(); it != thisWord.end(); it++)
            {
                wordSet.erase(*it);
            }
            thisWord.clear();
            int qlen = q.size();
            for (int i = 0; i < qlen; i++)
            {
                string newSrting = q.front();
                for (int j = 0; j < newString.size(); j++)
                {
                    for (char k = 'a'; k <= 'z'; k++)
                    {
                        newString[j] = k;
                        if (wordSet.count(newString))
                        {
                            stringMap[q.front()].push_back(newString);
                            if (newString == endWord)
                            {
                                bool = true;
                                break;
                            }
                            if (!thisWord.count(newString))
                            {
                                thisWord.insert(newString);
                                q.push(newString);
                            }
                        }
                    }
                }
                q.pop();
            }
            if (bool)
            {
                break;
            }
        }
        vector<string> tem;
        helper(output,stringMap,tem,endWord,beginWord);
    }
    void helper(vector<vector<string>>& output, map<string,vector<string>>& stringMap, vector<string>&tem, string endWord, string nowWord){
        if (nowWord == endWord)
        {
            tem.push_back(endWord);
            output.push_back(tem);
            tem.pop_back();
            return;
        }
        if (!stringMap.count(nowWord))
        {
            return;
        }
        tem.push_back(nowWord);
        int len = stringMap[nowWord].size();
        for (int i = 0; i < len; i++)
        {
            helper(output,stringMap,tem,endWord,stringMap[nowWord][i]);
        }
        tem.pop_back();
    }
};
// @lc code=end