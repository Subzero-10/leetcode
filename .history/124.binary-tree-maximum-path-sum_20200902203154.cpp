/*
 * @lc app=leetcode id=124 lang=cpp
 *
 * [124] Binary Tree Maximum Path Sum
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
    int maxPathSum(TreeNode* root) {
        vector<int> maxval(2);
        helper(root, maxval);
        return max(maxval[0],maxval[1]);
    }
    void helper(TreeNode* root, vector<int>& maxval)
    {
        if (!root)
        {
            maxval[0] = 0;
            maxval[1] = 0;
            return;
        }
        vector<int> maxvalLeft(2);
        vector<int> maxvalRight(2);
        helper(root->left, maxvalLeft);
        helper(root->right, maxvalRight);
        maxval[0] = max(maxvalLeft[0], maxvalRight[0]) + root->val;
        maxval[1] = max(max(maxvalLeft[1], maxvalRight[1]), maxvalLeft[0] + maxvalRight[0] + root->val);
    }

};
// @lc code=end

