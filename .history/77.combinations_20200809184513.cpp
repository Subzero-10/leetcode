/*
 * @lc app=leetcode id=77 lang=cpp
 *
 * [77] Combinations
 *
 * https://leetcode.com/problems/combinations/description/
 *
 * algorithms
 * Medium (52.30%)
 * Likes:    1538
 * Dislikes: 69
 * Total Accepted:    296.9K
 * Total Submissions: 543K
 * Testcase Example:  '4\n2'
 *
 * Given two integers n and k, return all possible combinations of k numbers
 * out of 1 ... n.
 * 
 * Example:
 * 
 * 
 * Input: n = 4, k = 2
 * Output:
 * [
 * ⁠ [2,4],
 * ⁠ [3,4],
 * ⁠ [2,3],
 * ⁠ [1,2],
 * ⁠ [1,3],
 * ⁠ [1,4],
 * ]
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> tem(k,0);
        vector<vector<int>> output;
        int pos = 0;
        nextpos(output, tem, pos, n, k, 0);
        return output;
    }
    void nextpos(vector<vector<int>> &output, vector<int>& tem, int pos, int n, int k, int i)
    {
        if (pos==(k-1))
        {
            for (; i < n-(k-pos)+1; i++)
            {
                tem[pos] = i+1;
                output.push_back(tem);
            }
        }
        else
        {
            for (; i < n-(k-pos)+1; i++)
            {
                tem[pos] = i+1;
                nextpos(output, tem, pos+1, n, k, i);
            }
        }
    }
};
// @lc code=end

