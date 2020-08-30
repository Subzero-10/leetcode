/*
 * @lc app=leetcode id=67 lang=cpp
 *
 * [67] Add Binary
 *
 * https://leetcode.com/problems/add-binary/description/
 *
 * algorithms
 * Easy (42.47%)
 * Likes:    1939
 * Dislikes: 282
 * Total Accepted:    484.1K
 * Total Submissions: 1.1M
 * Testcase Example:  '"11"\n"1"'
 *
 * Given two binary strings, return their sum (also a binary string).
 * 
 * The input strings are both non-empty and contains only characters 1 or 0.
 * 
 * Example 1:
 * 
 * 
 * Input: a = "11", b = "1"
 * Output: "100"
 * 
 * Example 2:
 * 
 * 
 * Input: a = "1010", b = "1011"
 * Output: "10101"
 * 
 * 
 * Constraints:
 * 
 * 
 * Each string consists only of '0' or '1' characters.
 * 1 <= a.length, b.length <= 10^4
 * Each string is either "0" or doesn't contain any leading zero.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string addBinary(string a, string b) {
        int lena = a.size();
        int lenb = b.size();
        int lenc = max(lena,lenb) + 1;
        string c(lenc, '0');
        bool along = true;
        if (lena<lenb)
        {
            along = false;
        }
        for (int i = 0; i < min(lena,lenb); i++)
        {
            int sum = (a[lena - i - 1] - '0') + (b[lenb - i - 1] - '0') + (c[lenc - i - 1] - '0');
            switch (sum)
            {
            case 0:
                c[lenc - i - 1] = '0';
                break;

            case 1:
                c[lenc - i - 1] = '1';
                break;
            
            case 2:
                c[lenc - i - 1] = '0';
                c[lenc - i] = '1';
                break;

            case 3:
                c[lenc - i - 1] = '1';
                c[lenc - i] = '1';
                break;
            default:
                break;
            }
        }
        if (along)
        {
            for (int i = 0; i < lena - lenb; i++)
            {
                int sum = (a[lena - lenb - i - 1] - '0') + (c[lenc - lenb - i - 1] - '0');
                switch (sum)
                {
                case 0:
                    c[lenc - lenb - i - 1] = '0';
                    break;

                case 1:
                    c[lenc - lenb - i - 1] = '1';
                    break;
                
                case 2:
                    c[lenc - lenb - i - 1] = '0';
                    c[lenc - lenb - i] = '1';
                    break;
                default:
                    break;
                }
            }
            
        }
        else
        {
            for (int i = 0; i < lenb - lena; i++)
            {
                int sum = (b[lenb - lena - i - 1] - '0') + (c[lenc - lena - i - 1] - '0');
                switch (sum)
                {
                case 0:
                    c[lenc - lena - i - 1] = '0';
                    break;

                case 1:
                    c[lenc - lena - i - 1] = '1';
                    break;
                
                case 2:
                    c[lenc - lena - i - 1] = '0';
                    c[lenc - lena - i] = '1';
                    break;
                default:
                    break;
                }
            }
        }
        return c;
        
    }
};
// @lc code=end

