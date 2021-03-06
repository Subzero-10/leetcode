/*
 * @lc app=leetcode id=87 lang=cpp
 *
 * [87] Scramble String
 *
 * https://leetcode.com/problems/scramble-string/description/
 *
 * algorithms
 * Hard (32.89%)
 * Likes:    551
 * Dislikes: 726
 * Total Accepted:    111.7K
 * Total Submissions: 330.8K
 * Testcase Example:  '"great"\n"rgeat"'
 *
 * Given a string s1, we may represent it as a binary tree by partitioning it
 * to two non-empty substrings recursively.
 * 
 * Below is one possible representation of s1 = "great":
 * 
 * 
 * ⁠   great
 * ⁠  /    \
 * ⁠ gr    eat
 * ⁠/ \    /  \
 * g   r  e   at
 * ⁠          / \
 * ⁠         a   t
 * 
 * 
 * To scramble the string, we may choose any non-leaf node and swap its two
 * children.
 * 
 * For example, if we choose the node "gr" and swap its two children, it
 * produces a scrambled string "rgeat".
 * 
 * 
 * ⁠   rgeat
 * ⁠  /    \
 * ⁠ rg    eat
 * ⁠/ \    /  \
 * r   g  e   at
 * ⁠          / \
 * ⁠         a   t
 * 
 * 
 * We say that "rgeat" is a scrambled string of "great".
 * 
 * Similarly, if we continue to swap the children of nodes "eat" and "at", it
 * produces a scrambled string "rgtae".
 * 
 * 
 * ⁠   rgtae
 * ⁠  /    \
 * ⁠ rg    tae
 * ⁠/ \    /  \
 * r   g  ta  e
 * ⁠      / \
 * ⁠     t   a
 * 
 * 
 * We say that "rgtae" is a scrambled string of "great".
 * 
 * Given two strings s1 and s2 of the same length, determine if s2 is a
 * scrambled string of s1.
 * 
 * Example 1:
 * 
 * 
 * Input: s1 = "great", s2 = "rgeat"
 * Output: true
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: s1 = "abcde", s2 = "caebd"
 * Output: false
 * 
 */

// @lc code=start
class Solution {
public:
    bool isScramble(string s1, string s2) {
        //printf("s1:%s,s2:%s\n",s1.c_str(),s2.c_str());
        if (s1.size()==1)
        {
            if (s1==s2)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        else
        {
            int step = s1.size()-1;
            while (step>0)
            {
                if ((isScramble(s1.substr(0,step), s2.substr(s2.size()-step,step))&&isScramble(s1.substr(step,s1.size()-step), s2.substr(0,s2.size()-step))) ||(isScramble(s1.substr(0,step), s2.substr(0,step))&&isScramble(s1.substr(step,s1.size()-step), s2.substr(step,s2.size()-step))))
                {
                    return true;
                }
                step--;
            }
            return false;
        }
        return true;
        
    }
};
// @lc code=end

