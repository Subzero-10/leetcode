/*
 * @lc app=leetcode id=129 lang=cpp
 *
 * [129] Sum Root to Leaf Numbers
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
    int sumNumbers(TreeNode* root) {
        if (!root)
        {
            return 0;
        }
        
        int tem = 0;
        int output = 0;
        helper(root, tem, output);
        return output;
    }
    void helper(TreeNode* root, int& tem, int& output) {
        tem = tem*10 + root->val;
        if ((!root->left) && (!root->right))
        {
            output += tem;
            tem = (tem - root->val)/10;
            return;
        }
        else
        {
            if (root->left)
            {
                helper(root->left, tem, output);
            }
            if (root->right)
            {
                helper(root->right, tem, output);
            }
        }
        tem = (tem - root->val)/10;
        return;
    }
};
// @lc code=end

