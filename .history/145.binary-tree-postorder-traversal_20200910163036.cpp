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
        TreeNode* head = root;
        s.push(root);
        while (!s.empty())
        {
            if (head == s.top()->left || head == s.top()->right)
            {
                head = s.top();
                s.pop();
                output.push_back(head->val);
            }
            head = s.top();
            if (head->right)
            {
                s.push(head->right);
            }
            if (head->left)
            {
                s.push(head->left);
            }
            
            if (!(head->left) && !(head->right))
            {
                head = s.top();
                s.pop();
                output.push_back(head->val);
            }
            
        }
        return output;
    }
};
// @lc code=end

