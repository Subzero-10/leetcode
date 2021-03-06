/*
 * @lc app=leetcode id=60 lang=cpp
 *
 * [60] Permutation Sequence
 *
 * https://leetcode.com/problems/permutation-sequence/description/
 *
 * algorithms
 * Medium (35.39%)
 * Likes:    1724
 * Dislikes: 339
 * Total Accepted:    204.2K
 * Total Submissions: 532.7K
 * Testcase Example:  '3\n3'
 *
 * The set [1,2,3,...,n] contains a total of n! unique permutations.
 * 
 * By listing and labeling all of the permutations in order, we get the
 * following sequence for n = 3:
 * 
 * 
 * "123"
 * "132"
 * "213"
 * "231"
 * "312"
 * "321"
 * 
 * 
 * Given n and k, return the k^th permutation sequence.
 * 
 * Note:
 * 
 * 
 * Given n will be between 1 and 9 inclusive.
 * Given k will be between 1 and n! inclusive.
 * 
 * 
 * Example 1:
 * 
 * 
 * Input: n = 3, k = 3
 * Output: "213"
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: n = 4, k = 9
 * Output: "2314"
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    string getPermutation(int n, int k) {
        string str = "123456789";
        string strtem = str.substr(0,n);
        string stroutput;
        int a[9] = {1,2,6,24,120,720,5040,40320,362880};
        for (; n>1; n--)
        {
            int pos = k/a[n-2];
            k = k - pos*a[n-2];
            stroutput.push_back(strtem[pos]);
            strtem.erase(pos,1);
        }
        stroutput.push_back(strtem[0]);
        return stroutput;
    }
};
// @lc code=end

