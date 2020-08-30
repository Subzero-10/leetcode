/*
 * @lc app=leetcode id=76 lang=cpp
 *
 * [76] Minimum Window Substring
 *
 * https://leetcode.com/problems/minimum-window-substring/description/
 *
 * algorithms
 * Hard (33.47%)
 * Likes:    4702
 * Dislikes: 324
 * Total Accepted:    410.8K
 * Total Submissions: 1.2M
 * Testcase Example:  '"ADOBECODEBANC"\n"ABC"'
 *
 * Given a string S and a string T, find the minimum window in S which will
 * contain all the characters in T in complexity O(n).
 * 
 * Example:
 * 
 * 
 * Input: S = "ADOBECODEBANC", T = "ABC"
 * Output: "BANC"
 * 
 * 
 * Note:
 * 
 * 
 * If there is no such window in S that covers all characters in T, return the
 * empty string "".
 * If there is such window, you are guaranteed that there will always be only
 * one unique minimum window in S.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string minWindow(string s, string t) {
        map<char, int> temstr;
        set<int> tempos;
        int lens = s.size();
        int lent = t.size();
        int minlen = lens+2;
        int begin = 0;
        for (int i = 0; i < lent; i++)
        {
            temstr[t[i]] = -1;
        }
        for (int i = 0; i < lens; i++)
        {
            if (temstr.find(s[i]) != temstr.end())
            {
                if (temstr[s[i]] == -1)
                {
                    tempos.insert(i);
                    temstr[s[i]] = i;
                }
                else
                {
                    tempos.erase(temstr[s[i]]);
                    tempos.insert(i);
                    temstr[s[i]] = i;
                }
                if (tempos.size()==lent)
                {
                    if (minlen <= i-*tempos.begin()+1)
                    {
                        minlen = i-*tempos.begin()+1;
                        begin = *tempos.begin();
                    }
                }
            }
        }
        if (minlen == lens + 2)
        {
            return "";
        }
        return s.substr(begin, minlen);
    }
};
// @lc code=end

