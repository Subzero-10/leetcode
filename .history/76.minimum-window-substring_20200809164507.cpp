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
        int minbegin = 0;
        int cnt = 0;
        for (int i = 0; i < lent; i++)
        {
            temstr[t[i]]++;
        }
        for (int i = 0; i < lens; i++)
        {
            if (--temstr[s[i]] >= 0)
            {
                cnt++;
            }
            while (cnt == lent)
            {
                if (minlen > i-begin+1)
                {
                    minlen = i-begin+1;
                    minbegin = begin;
                }
                if (++temstr[s[i]] > 0)
                {
                    cnt--;
                }
                begin++;
            }
            
        }
        return minbegin == -1 ? "" : s.substr(minbegin, minlen);
    }
};
// @lc code=end

