/*
 * @lc app=leetcode id=96 lang=cpp
 *
 * [96] Unique Binary Search Trees
 *
 * https://leetcode.com/problems/unique-binary-search-trees/description/
 *
 * algorithms
 * Medium (49.84%)
 * Likes:    3643
 * Dislikes: 134
 * Total Accepted:    315.7K
 * Total Submissions: 595K
 * Testcase Example:  '3'
 *
 * Given n, how many structurally unique BST's (binary search trees) that store
 * values 1 ... n?
 * 
 * Example:
 * 
 * 
 * Input: 3
 * Output: 5
 * Explanation:
 * Given n = 3, there are a total of 5 unique BST's:
 * 
 * ⁠  1         3     3      2      1
 * ⁠   \       /     /      / \      \
 * ⁠    3     2     1      1   3      2
 * ⁠   /     /       \                 \
 * ⁠  2     1         2                 3
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 1 <= n <= 19
 * 
 * 
 */

// @lc code=start
class Solution {
public:
    int numTrees(int n) {
        if (n==0)
        {
            return 0;
        }
        else
        {
            return helper(1,n);
        }
    }
    int helper(int left, int right){
        int output = 0;
        if (left>=right)
        {
            return 1;
        }
        
        for (int i = left; i <= right; i++)
        {
            output += helper(left, i-1)*helper(i+1,right);
        }
        return output;
    }
};
// @lc code=end

