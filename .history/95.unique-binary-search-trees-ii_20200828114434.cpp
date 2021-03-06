/*
 * @lc app=leetcode id=95 lang=cpp
 *
 * [95] Unique Binary Search Trees II
 *
 * https://leetcode.com/problems/unique-binary-search-trees-ii/description/
 *
 * algorithms
 * Medium (38.68%)
 * Likes:    2375
 * Dislikes: 161
 * Total Accepted:    199.2K
 * Total Submissions: 488.2K
 * Testcase Example:  '3'
 *
 * Given an integer n, generate all structurally unique BST's (binary search
 * trees) that store values 1 ... n.
 * 
 * Example:
 * 
 * 
 * Input: 3
 * Output:
 * [
 * [1,null,3,2],
 * [3,2,null,1],
 * [3,1,null,null,2],
 * [2,1,3],
 * [1,null,2,null,3]
 * ]
 * Explanation:
 * The above output corresponds to the 5 unique BST's shown below:
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
 * 0 <= n <= 8
 * 
 * 
 */

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        return helper(1,n);
    }
    vector<TreeNode*> helper(int left, int right){
        vector<TreeNode*> output;
        if (left>right)
        {
            TreeNode* tem = NULL;
            output.push_back(tem);
            return output;
        }
        else if (left==right)
        {
            TreeNode* tem = new TreeNode(left);
            output.push_back(tem);
            return output;
        }
        
        for (int i = left; i <= right; i++)
        {
            vector<TreeNode*> outputleft(helper(left, i-1));
            vector<TreeNode*> outputright(helper(i+1,right););
            for (auto a:outputleft)
            {
                for (auto b:outputright)
                {
                    TreeNode* tem = new TreeNode(i);
                    tem->left = a;
                    tem->right = b;
                    output.push_back(tem);
                }
            }
        }
        return output;
    }
};
// @lc code=end

