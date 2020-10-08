/*
 * @lc app=leetcode id=172 lang=cpp
 *
 * [172] Factorial Trailing Zeroes
 */

// @lc code=start
class Solution {
public:
    int trailingZeroes(int n) {
        int a = 0;
        int b = 0;
        for (int i = 1; i < 6; i++)
        {
            b = n/(int)pow(5,i);
            if (b==0)
            {
                break;
            }
            a += b;
        }
        return a;
    }
};
// @lc code=end

