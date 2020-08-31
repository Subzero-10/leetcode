/*
 * @lc app=leetcode id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        queue<TreeNode*> q;
        if (root != NULL)
        {
            q.push(root);
        }
        int len;
        vector<vector<int>> output;
        while (q.size() != 0)
        {
            len = q.size();
            <vector<int> tem;
            for (int i = 0; i < len; i++)
            {
                tem.push_back(q.front()->val);
                if (q.front()->left != NULL)
                {
                    q.push(q.front()->left);
                }
                if (q.front()->right != NULL)
                {
                    q.push(q.front()->right);
                }
                q.pop();
            }
            output.push_back(tem);
        }
        return output;
    }
};
// @lc code=end

