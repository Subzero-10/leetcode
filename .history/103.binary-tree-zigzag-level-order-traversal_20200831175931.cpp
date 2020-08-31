/*
 * @lc app=leetcode id=103 lang=cpp
 *
 * [103] Binary Tree Zigzag Level Order Traversal
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        stack<TreeNode*> q;
        if (root != NULL)
        {
            q.push(root);
        }
        int len;
        vector<vector<int>> output;
        bool a = true;
        while (q.size() != 0)
        {
            len = q.size();
            vector<int> tem;
            for (int i = 0; i < len; i++)
            {
                tem.push_back(q.top()->val);
                if (a)
                {
                    if (q.top()->left != NULL)
                    {
                        q.push(q.top()->left);
                    }
                    if (q.top()->right != NULL)
                    {
                        q.push(q.top()->right);
                    }
                }
                else
                {
                    if (q.top()->right != NULL)
                    {
                        q.push(q.top()->right);
                    }
                    if (q.top()->left != NULL)
                    {
                        q.push(q.top()->left);
                    }
                }
                q.pop();
            }
            a = !a;
            output.push_back(tem);
        }
        return output;
    }
};
// @lc code=end

