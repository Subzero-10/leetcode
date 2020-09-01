/*
 * @lc app=leetcode id=113 lang=cpp
 *
 * [113] Path Sum II
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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> output;
        vector<int> tem;
        helper(root, sum, 0, output, tem);
        return output;
    }
    void helper(TreeNode* root, int sum, int nowsum, vector<vector<int>>& output, vector<int>& tem){
        if (root == NULL)
        {
            return;
        }
        nowsum += root->val;
        tem.push_back(root->val);
        if (root->left == NULL && root->right== NULL)
        {
            if (sum == nowsum)
            {
                output.push_back(tem);
            }
            return;
        }
        vector<int>& temright(tem);
        vector<int>& temleft(tem);
        helper(root->left, sum, nowsum, output, temleft);
        helper(root->right, sum, nowsum, output, temright);
    }
};
// @lc code=end

