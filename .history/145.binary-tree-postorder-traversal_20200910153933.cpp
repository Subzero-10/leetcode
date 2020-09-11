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
        TreeNode* tem = root;
        vector<TreeNode*> output;
        while (!s.empty())
        {
            if (tem)
            {
                if (tem == s.top())
                {
                    tem = NULL;
                    continue;
                }
                s.push(tem);
                tem = tem->left;
            }
            else
            {
                tem = s.top();
                if (tem->right)
                {
                    if (tem->right->val == output[(int)output.size()-1])
                    {
                        output.push_back(tem->val);
                        s.pop();
                    }
                    else
                    {
                        tem = tem->right;
                        s.push(tem);
                    }
                }
                else
                {
                    output.push_back(tem->val);
                    s.pop();
                }
                tem = s.top();
            }
            
        }
        return output;
    }
};
// @lc code=end

