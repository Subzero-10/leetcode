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
        bool a = true;
        int step = 1;
        TreeNode* head = new TreeNode(0, NULL, s.top());
        s.pop();
        while (!s.empty())
        {
            TreeNode* last = head;
            TreeNode* tem = last->right;
            for (int i = 0; i < step; i++)
            {
                if (tem->val >= s.top()->val)
                {
                    last->right = s.top();
                    s.top()->left = NULL;
                    s.top()->right = tem;
                    s.pop();
                    a = false;
                    break;
                }
                last = tem;
                tem = tem->right;
            }
            if (a)
            {
                last->right = s.top();
                s.top()->left = NULL;
                s.pop();
                a = true;
            }
            step++;
        }
    }
    void pushs(TreeNode* root, stack<TreeNode*>& s)
    {
        if (root != NULL)
        {
            s.push(root);
            pushs(root->left, s);
            pushs(root->right, s);
        }
    }
};
// @lc code=end

