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
            if (s.top()->left)
            {
                s.push(s.top()->left);
            }
            if (s.top()->right)
            {
                s.push(s.top()->right);
            }
            output.push_back(s.top()->val);
            s.pop();
        }
        return output;
    }
};
// @lc code=end

