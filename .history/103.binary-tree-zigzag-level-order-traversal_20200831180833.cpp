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
        stack<TreeNode*> s;
        if (root != NULL)
        {
            s.push(root);
        }
        int len;
        vector<vector<int>> output;
        bool a = true;
        helper(s, output, a);
        return output;
    }
    void helper(stack<TreeNode*>& s, vector<vector<int>>& output, bool a)
    {
        if (s.size() != 0)
        {
            len = s.size();
            vector<int> tem;
            stack<TreeNode*> ss;
            for (int i = 0; i < len; i++)
            {
                tem.push_back(s.top()->val);
                if (a)
                {
                    if (s.top()->left != NULL)
                    {
                        ss.push(s.top()->left);
                    }
                    if (s.top()->right != NULL)
                    {
                        ss.push(s.top()->right);
                    }
                }
                else
                {
                    if (s.top()->right != NULL)
                    {
                        ss.push(s.top()->right);
                    }
                    if (s.top()->left != NULL)
                    {
                        ss.push(s.top()->left);
                    }
                }
                s.pop();
            }
            output.push_back(tem);
            helper(ss, output, !a);
        }
    }
};
// @lc code=end

