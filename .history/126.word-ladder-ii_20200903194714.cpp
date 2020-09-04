/*
 * @lc app=leetcode id=126 lang=cpp
 *
 * [126] Word Ladder II
 */

// @lc code=start
class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        static const auto io_sync_off = []()
        {
            // turn off sync
            std::ios::sync_with_stdio(false);
            // untie in/out streams
            std::cin.tie(nullptr);
            return nullptr;
        }();
        vector<vector<string>> output;
        int len = wordList.size();
        bool haveEnd = false;
        for (int i = 0; i < len; i++)
        {
            if (compareString(wordList[i], endWord) == 0)
            {
                haveEnd = true;
                swap(wordList[0],wordList[i]);
            }
        }
        if (!haveEnd)
        {
            return output;
        }
        haveEnd = false;
        wordList.push_back(beginWord);
        queue<int> q;
        vector<vector<int>> stringMap(len+1);
        q.push(len);
        int step = 0;
        vector<int> havefound(len+1,len+1);
        while (!q.empty())
        {
            int qlen = q.size();
            for (int i = 0; i < qlen; i++)
            {
                for (int j = 0; j < len; j++)
                {
                    if (havefound[j]>step)
                    {
                        if(compareString(wordList[q.front()], wordList[j]) == 1)
                        {
                            q.push(j);
                            havefound[j] = step;
                            stringMap[q.front()].push_back(j);
                            if (j == 0)
                            {
                                haveEnd = true;
                            }
                        }
                    }
                    else if(havefound[j] == step)
                    {
                        if(compareString(wordList[q.front()], wordList[j]) == 1)
                        {
                            stringMap[q.front()].push_back(j);
                        }
                    }
                }
                q.pop();
            }
            step++;
            if (haveEnd)
            {
                break;
            }
        }
        if (haveEnd)
        {
            vector<string> tem;
            helper(output,tem,stringMap,len,wordList);
        }
        return output;
    }
    int compareString(string s1, string s2){
        int a = 0;
        for (int i = 0; i < (int)s1.size(); i++)
        {
            if (s1[i] != s2[i])
            {
                a++;
            }
        }
        return a;
    }
    void helper(vector<vector<string>>& output,vector<string>& tem, vector<vector<int>>& stringMap, int i, vector<string>& wordList){
        tem.push_back(wordList[i]);
        if (i == 0)
        {
            output.push_back(tem);
            tem.pop_back();
            return;
        }
        if (stringMap[i].empty())
        {
            tem.pop_back();
            return;
        }
        for (int j = 0; j < (int)stringMap[i].size(); j++)
        {
            helper(output,tem,stringMap,stringMap[i][j],wordList);
        }
        tem.pop_back();
    }
};
// @lc code=end