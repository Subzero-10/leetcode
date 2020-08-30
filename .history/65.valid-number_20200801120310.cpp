/*
 * @lc app=leetcode id=65 lang=cpp
 *
 * [65] Valid Number
 *
 * https://leetcode.com/problems/valid-number/description/
 *
 * algorithms
 * Hard (14.80%)
 * Likes:    746
 * Dislikes: 4859
 * Total Accepted:    172K
 * Total Submissions: 1.1M
 * Testcase Example:  '"0"'
 *
 * Validate if a given string can be interpreted as a decimal number.
 * 
 * Some examples:
 * "0" => true
 * " 0.1 " => true
 * "abc" => false
 * "1 a" => false
 * "2e10" => true
 * " -90e3   " => true
 * " 1e" => false
 * "e3" => false
 * " 6e-1" => true
 * " 99e2.5 " => false
 * "53.5e93" => true
 * " --6 " => false
 * "-+3" => false
 * "95a54e53" => false
 * 
 * Note: It is intended for the problem statement to be ambiguous. You should
 * gather all requirements up front before implementing one. However, here is a
 * list of characters that can be in a valid decimal number:
 * 
 * 
 * Numbers 0-9
 * Exponent - "e"
 * Positive/negative sign - "+"/"-"
 * Decimal point - "."
 * 
 * 
 * Of course, the context of these characters also matters in the input.
 * 
 * Update (2015-02-10):
 * The signature of the C++ function had been updated. If you still see your
 * function signature accepts a const char * argument, please click the reload
 * button to reset your code definition.
 * 
 */

// @lc code=start
class Solution {
public:
    bool isNumber(string s) {
        //符号只能出现在第一位，和e的后一位；e前后必须有数；e后不能有小数，e前只能有一个小数;空格只能在最前最后
        int len = s.size();
        bool schar = false;
        bool se = false;
        bool sdot = false;
        bool sspe = false;
        bool snum = false;
        for (int i = 0; i < len; i++)
        {
            if ((s[i]-'0')>=0 && (s[i]-'0')<=9)
            {
                snum = true;
                continue;
            }
            else if (s[i] == 'e')
            {
                if (!snum || i+1==len || !((s[i+1]-'0')>=0 && (s[i+1]-'0')<=9) || se)
                {
                    return false;
                }
                se = true;
            }
            else if (s[i] == '.')
            {
                
                if (sdot || se)
                {
                    return false;
                }
                sdot = true;
            }
            else if (s[i] == ' ')
            {
                if (i+1 == len)
                {
                    break;
                }
                else
                {
                    if (!sspe)
                    {
                        if (s[i+1] != ' ')
                        {
                            sspe = true;
                        }
                    }
                    else
                    {
                        if (s[i+1] != ' ')
                        {
                            return false;
                        }
                    }
                }
            }
            else if (s[i] == '+' || s[i] == '-')
            {
                if (i==0)
                {
                    continue;
                }
                else if (s[i-1] == ' ')
                {
                    continue;
                }
                else if (s[i-1] == 'e')
                {
                    continue;
                }
            }
            else
            {
                return false;
            }
        }
        if (snum)
        {
            return true;
        }
        return false;
        
    }
};
// @lc code=end

