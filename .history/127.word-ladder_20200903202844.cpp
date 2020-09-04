/*
 * @lc app=leetcode id=127 lang=cpp
 *
 * [127] Word Ladder
 */

// @lc code=start
class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int wlen = wordList.size();
        vector<int> havepath(wlen);
        queue<int> q;
        wordList.push_back(beginWord);
        q.push(wlen);
        int count = 0;
        int output = 0;
        while (!q.empty())
        {
            int len = q.size();
            for (int i = 0; i < len; i++)
            {
                for (int j = 0; j < wlen; j++)
                {
                    if (havepath[j] == 0)
                    {
                        if (compareString(endWord, wordList[j]) == 0)
                        {
                            count++;
                            output = count;
                            break;
                        }
                        
                        if (compareString(wordList[q.front()], wordList[j]) == 1)
                        {
                            count++;
                            q.push(j);
                            havepath[j] = 1;
                        }
                    }
                }
                q.pop();
            }
        }
        return output;
    }
    int compareString(string s1, string s2){
        int a = 0;
        char* str1 = const_cast<char*>(s1.c_str());
        char* str2 = const_cast<char*>(s2.c_str());
        for (int i = 0; i < (int)s1.size(); i++)
        {
            if (str1[i] != str2[i])
            {
                a++;
            }
        }
        return a;
    }
};
// @lc code=end

