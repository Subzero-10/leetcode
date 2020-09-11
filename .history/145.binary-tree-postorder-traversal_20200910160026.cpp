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
        unordered_set<int> st;
        s.push(root);
        while (!s.empty())
        {
            TreeNode* tem = s.top();
            if (tem->left)
            {
                if (st.count(tem->left->val))
                {
                    if (st.count(tem->right->val))
                    {
                        output.push_back(tem->val);
                        st.insert(tem->val);
                        s.pop();
                    }
                    else
                    {
                        s.push(tem->right);
                    }
                }
                else
                {
                    s.push(tem->left);
                }
            }
            else
            {
                if (tem->right)
                {
                    s.push(tem->right);
                }
                else
                {
                    output.push_back(tem->val);
                    st.insert(tem->val);
                    s.pop();
                }
            }
            
        }
        return output;
    }
};
// @lc code=end

