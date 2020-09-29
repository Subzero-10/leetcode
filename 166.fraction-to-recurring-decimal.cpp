/*
 * @lc app=leetcode id=166 lang=cpp
 *
 * [166] Fraction to Recurring Decimal
 */

// @lc code=start
class Solution {
public:
    string fractionToDecimal(int numerator1, int denominator) {
        string output;
        long numerator = numerator1;
        if (numerator%denominator == 0)
        {
            return to_string(numerator/denominator);
        }
        else if (numerator%denominator != 0 && numerator/denominator != 0)
        {
            output = to_string(numerator/denominator);
            output += ".";
            numerator = numerator%denominator*10;
        }
        else if (numerator%denominator != 0 && numerator/denominator == 0)
        {
            if ((numerator<0&&denominator<0) || (numerator>0&&denominator>0))
            {
                output += "0.";
            }
            else
            {
                output += "-0.";
            }
            numerator = numerator%denominator*10;
        }
        denominator = abs(denominator);
        numerator = abs(numerator);
        unordered_map<int,int>mp;
        string tem;
        int i = 0;
        while (numerator != 0 )
        {
            if (mp.count(numerator))
            {
                break;
            }
            else
            {
                mp[numerator] = i;
                if (numerator/denominator != 0)
                {
                    tem += to_string(numerator/denominator);
                }
                else
                {
                    tem += to_string(0);
                }
                numerator = numerator%denominator*10;
            }
            i++;
        }
        if (numerator == 0)
        {
            return output+tem;
        }
        else
        {
            tem.insert(mp[numerator],"(");
            tem = tem+")";
            return output+tem;
        }
        
    }
};
// @lc code=end

