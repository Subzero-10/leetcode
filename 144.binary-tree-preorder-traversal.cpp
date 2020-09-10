/*
 * @lc app=leetcode id=144 lang=cpp
 *
 * [144] Binary Tree Preorder Traversal
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
    vector<int> preorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        if (root)
        {
            s.push(root);
        }
        vector<int> output;
        while (!s.empty())
        {
            TreeNode* n = s.top();
            output.push_back(s.top()->val);
            s.pop();
            if (n->right)
            {
                s.push(n->right);
            }
            if (n->left)
            {
                s.push(n->left);
            }
        }
        return output;
    }
};
// @lc code=end

