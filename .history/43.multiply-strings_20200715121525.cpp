/*
 * @lc app=leetcode id=43 lang=cpp
 *
 * [43] Multiply Strings
 *
 * https://leetcode.com/problems/multiply-strings/description/
 *
 * algorithms
 * Medium (32.76%)
 * Likes:    1733
 * Dislikes: 795
 * Total Accepted:    294.6K
 * Total Submissions: 875.2K
 * Testcase Example:  '"2"\n"3"'
 *
 * Given two non-negative integers num1 and num2 represented as strings, return
 * the product of num1 and num2, also represented as a string.
 * 
 * Example 1:
 * 
 * 
 * Input: num1 = "2", num2 = "3"
 * Output: "6"
 * 
 * Example 2:
 * 
 * 
 * Input: num1 = "123", num2 = "456"
 * Output: "56088"
 * 
 * 
 * Note:
 * 
 * 
 * The length of both num1 and num2 is < 110.
 * Both num1 and num2 contain only digits 0-9.
 * Both num1 and num2 do not contain any leading zero, except the number 0
 * itself.
 * You must not use any built-in BigInteger library or convert the inputs to
 * integer directly.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string multiply(string num1, string num2) {
        int len1 = num1.size();
        int len2 = num2.size();
        int number1 = 0;
        int number2 = 0;
        int pronum = 0;
        string pronumOutput;
        for (int i = 0; i < len1; i++)
        {
            number1 += (num1[len1 - i -1] - '0')*pow(10,i);
        }
        for (int i = 0; i < len2; i++)
        {
            number2 += (num2[len2 - i -1] - '0')*pow(10,i);
        }
        pronum = number1*number2;
        if (pronum == 0)
        {
            return "0";
        }
        bool first0 = true;
        for (int i = 4; i >= 0; i--)
        {
            if (pronum/pow(10,i) == 0)
            {
                printf("2");
                pronumOutput += ('0'+ pronum/(int)pow(10,i));
                pronum = pronum % (int)pow(10,i);
                first0 = false;
            }

        }
        return pronumOutput;
    }
};
// @lc code=end

