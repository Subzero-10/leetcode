/*
 * @lc app=leetcode id=168 lang=cpp
 *
 * [168] Excel Sheet Column Title
 */

// @lc code=start
class Solution {
public:
    string convertToTitle(int n) {
        n = n-1;
        if(n==-1){
            return "";
        }
        int a = n%26;
        int b = (n-a)/26;
        char s = ('A'+a);
        return convertToTitle(b) + s;
    }
};
// @lc code=end

