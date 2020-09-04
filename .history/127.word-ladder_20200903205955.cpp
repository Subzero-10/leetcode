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
        int slen = beginWord.size();
        unordered_set<string> wordSet(wordList.begin(),wordList.end());
        if (!wordSet.count(endWord))
        {
            return 0;
        }
        queue<string> q;
        q.push(beginWord);
        int count = 1;
        int output = 0;
        while (!q.empty())
        {
            int len = q.size();
            for (int i = 0; i < len; i++)
            {
                string newWord = q.front();
                for (int j = 0; j < slen; j++)
                {
                    for (char k = 'a'; k < 'z'; k++)
                    {
                        newWord[j] = k;
                        if (wordSet.count(newWord))
                        {
                            if (newWord == endWord)
                            {
                                output = count++;
                                return output;
                            }
                            q.push(newWord);
                            wordSet.erase(newWord);
                        }
                    }
                }
                q.pop();
            }
            count++;
        }
        return output;
    }
};
// @lc code=end

