/*
 * @lc app=leetcode id=112 lang=cpp
 *
 * [112] Path Sum
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
    bool hasPathSum(TreeNode* root, int sum) {
        return helper(root, sum, 0);
    }
    bool helper(TreeNode* root, int sum, int nowsum){
        if (root == NULL)
        {
            return false;
        }
        nowsum += root->val;
        if (root->left == NULL && root->right== NULL)
        {
            return sum == nowsum;
        }
        return helper(root->left, sum, nowsum) || helper(root->right, sum, nowsum);
    }
};
// @lc code=end

