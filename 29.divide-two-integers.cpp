/*
 * @lc app=leetcode id=29 lang=cpp
 *
 * [29] Divide Two Integers
 *
 * https://leetcode.com/problems/divide-two-integers/description/
 *
 * algorithms
 * Medium (16.17%)
 * Likes:    1009
 * Dislikes: 4778
 * Total Accepted:    256.2K
 * Total Submissions: 1.6M
 * Testcase Example:  '10\n3'
 *
 * Given two integers dividend and divisor, divide two integers without using
 * multiplication, division and mod operator.
 * 
 * Return the quotient after dividing dividend by divisor.
 * 
 * The integer division should truncate toward zero, which means losing its
 * fractional part. For example, truncate(8.345) = 8 and truncate(-2.7335) =
 * -2.
 * 
 * Example 1:
 * 
 * 
 * Input: dividend = 10, divisor = 3
 * Output: 3
 * Explanation: 10/3 = truncate(3.33333..) = 3.
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: dividend = 7, divisor = -3
 * Output: -2
 * Explanation: 7/-3 = truncate(-2.33333..) = -2.
 * 
 * 
 * Note:
 * 
 * 
 * Both dividend and divisor will be 32-bit signed integers.
 * The divisor will never be 0.
 * Assume we are dealing with an environment which could only store integers
 * within the 32-bit signed integer range: [−2^31,  2^31 − 1]. For the purpose
 * of this problem, assume that your function returns 2^31 − 1 when the
 * division result overflows.
 * 
 * 
 */

// @lc code=start
#include <cmath>
class Solution {
public:
    int divide(int dividend, int divisor) {
        if (dividend == 0)
        {
            return 0;
        }
        if (divisor == 1)
        {
            return dividend;
        }
        if (divisor == -1)
        {
            if (dividend == -2147483648)
            {
                return 2147483647;
            }
            
            return -dividend;
        }
        if ((dividend > 0 && divisor > 0) || (dividend < 0 && divisor < 0))
        {
            return division(abs((long)dividend), abs((long)divisor));
        }
        else
        {
            return -division(abs((long)dividend), abs((long)divisor));
        }
        
        
    }
    int division(long dividend, long divisor){
        if (dividend - divisor < 0)
        {
            return 0;
        }
        else
        {
            return 1+division(dividend - divisor, divisor);
        }
    }
};
// @lc code=end

