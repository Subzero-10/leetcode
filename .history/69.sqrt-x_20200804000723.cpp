/*
 * @lc app=leetcode id=69 lang=cpp
 *
 * [69] Sqrt(x)
 *
 * https://leetcode.com/problems/sqrtx/description/
 *
 * algorithms
 * Easy (32.98%)
 * Likes:    1368
 * Dislikes: 1927
 * Total Accepted:    567.3K
 * Total Submissions: 1.7M
 * Testcase Example:  '4'
 *
 * Implement int sqrt(int x).
 * 
 * Compute and return the square root of x, where x is guaranteed to be a
 * non-negative integer.
 * 
 * Since the return type is an integer, the decimal digits are truncated and
 * only the integer part of the result is returned.
 * 
 * Example 1:
 * 
 * 
 * Input: 4
 * Output: 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 8
 * Output: 2
 * Explanation: The square root of 8 is 2.82842..., and since 
 * the decimal part is truncated, 2 is returned.
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int mySqrt(int x) {
        if (x==1)
        {
            return 1;
        }
        
        long left = 0;
        long right = x;
        long mid = x/16;
        while (left!=(right-1))
        {
            if (mid*mid>x)
            {
                right = mid;
                mid = (mid - left)/16 + left;
            }
            else if (mid*mid == x)
            {
                return mid;
            }
            else
            {
                left = mid;
                mid = (right - mid)/2 + mid;
            }
            
        }
        return (int)left;
    }
};
// @lc code=end

