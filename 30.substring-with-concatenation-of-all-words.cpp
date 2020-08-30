/*
 * @lc app=leetcode id=30 lang=cpp
 *
 * [30] Substring with Concatenation of All Words
 *
 * https://leetcode.com/problems/substring-with-concatenation-of-all-words/description/
 *
 * algorithms
 * Hard (24.81%)
 * Likes:    799
 * Dislikes: 1195
 * Total Accepted:    171.5K
 * Total Submissions: 683.7K
 * Testcase Example:  '"barfoothefoobarman"\n["foo","bar"]'
 *
 * You are given a string, s, and a list of words, words, that are all of the
 * same length. Find all starting indices of substring(s) in s that is a
 * concatenation of each word in words exactly once and without any intervening
 * characters.
 * 
 * 
 * 
 * Example 1:
 * 
 * 
 * Input:
 * ⁠ s = "barfoothefoobarman",
 * ⁠ words = ["foo","bar"]
 * Output: [0,9]
 * Explanation: Substrings starting at index 0 and 9 are "barfoo" and "foobar"
 * respectively.
 * The output order does not matter, returning [9,0] is fine too.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input:
 * ⁠ s = "wordgoodgoodgoodbestword",
 * ⁠ words = ["word","good","best","word"]
 * Output: []
 * 
 * 
 */

// @lc code=start

//Time Limit Exceeded 窗口法

class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int index = 0;
        int nowInd = 0;
        int wordLength = words.size();
        vector<string> newWords(words);
        vector<int> returnWords;

        for (int i = 0; i < s.length(); i++)
        {
            for (int ii = 0; ii < wordLength; ii++)
            {
                if (!s.substr(nowInd,newWords[ii].length()).compare(newWords[ii]) )
                {
                    newWords.erase(newWords.begin()+ii);
                    if (newWords.empty())
                    {
                        returnWords.push_back(i);
                        break;
                    }
                    else
                    {
                        nowInd = nowInd + newWords[ii].length();
                        wordLength--;
                        ii = -1;
                    }
                }
            }
            wordLength = words.size();
            newWords.assign(words.begin(),words.end());
            nowInd = i + 1;
        }
        return returnWords;
    }
};
// @lc code=end

