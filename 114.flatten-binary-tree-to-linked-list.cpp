/*
 * @lc app=leetcode id=114 lang=cpp
 *
 * [114] Flatten Binary Tree to Linked List
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
    void flatten(TreeNode* root) {
        if (root == NULL)
        {
            return;
        }
        
        stack<TreeNode*> s;
        pushs(root, s);
        TreeNode* tem = root;
        s.pop();
        while (!s.empty())
        {
            tem->right = s.top();
            tem->left = NULL;
            tem = s.top();
            s.pop();
        }
        
    }
    void pushs(TreeNode* root, stack<TreeNode*>& s)
    {
        if (root != NULL)
        {
            pushs(root->right, s);
            pushs(root->left, s);
            s.push(root);
        }
    }
};
// @lc code=end

