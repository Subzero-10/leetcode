/*
 * @lc app=leetcode id=110 lang=cpp
 *
 * [110] Balanced Binary Tree
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
    bool isBalanced(TreeNode* root) {
        int i = 0;
        return helper(root, i);
    }
    bool helper(TreeNode* root, int& i){
        if (root == NULL)
        {
            i = 0;
            return true;
        }
        int lefti;
        int righti;
        if (helper(root->left, lefti)&&helper(root->right, righti))
        {
            return false;
        }
        if ((left>right+1)||(right>left+1))
        {
            return false;
        }
        else
        {
            i = max(left,right) + 1;
            return true;
        }
        
    }
};
// @lc code=end

