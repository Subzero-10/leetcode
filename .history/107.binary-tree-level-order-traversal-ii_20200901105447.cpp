/*
 * @lc app=leetcode id=107 lang=cpp
 *
 * [107] Binary Tree Level Order Traversal II
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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> tem;
        queue<TreeNode*> q;
        if (root != NULL)
        {
            q.push(root);
        }
        int len;
        while (q.size() != 0)
        {
            len = q.size();
            vector<int> temtem;
            for (int i = 0; i < len; i++)
            {
                temtem.push_back(q.front->val);
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
            tem.push_back(temtem);
        }
        vector<vector<int>> output;
        while (!tem.empty())
        {
            output.push_back(tem.back());
            tem.pop();
        }
        return output;;
    }
};
// @lc code=end

