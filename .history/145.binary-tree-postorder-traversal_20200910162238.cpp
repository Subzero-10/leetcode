/*
 * @lc app=leetcode id=145 lang=cpp
 *
 * [145] Binary Tree Postorder Traversal
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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> s;
        vector<int> output;
        if (!root)
        {
            return output;
        }
        TreeNode* head;
        s.push(root);
        while (!s.empty())
        {
            if (head == s.top()->left || head == s.top()->right)
            {
                head = s.top();
                s.pop();
                output.push_back(head);
            }
            
            if (s.top()->right)
            {
                s.push(s.top()->right);
            }
            if (s.top()->left)
            {
                s.push(s.top()->left);
            }
            
            if (!s.top()->left && !s.top()->right)
            {
                head = s.top();
                s.pop();
                output.push_back(head);
            }
            
        }
        return output;
    }
};
// @lc code=end

