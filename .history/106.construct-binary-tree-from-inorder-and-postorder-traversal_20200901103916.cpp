/*
 * @lc app=leetcode id=106 lang=cpp
 *
 * [106] Construct Binary Tree from Inorder and Postorder Traversal
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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (preorder.size() == 0)
        {
            return NULL;
        }
        TreeNode* root = new TreeNode(postorder[(int)postorder.size()-1]);
        int i = 0;
        for (i = 0; i < (int)inorder.size(); i++)
        {
            if (inorder[i] == postorder[(int)postorder.size()-1])
            {
                break;
            }
        }
        vector<int> postleft(postorder.begin(), postorder.begin()+i);
        vector<int> inleft(inorder.begin(), inorder.begin()+i);
        vector<int> postright(postorder.begin()+i, postorder.end()-1);
        vector<int> inright(inorder.begin()+1+i, inorder.end());
        root->left = buildTree(inleft, postleft);
        root->right = buildTree(inright, postright);
        return root;
    }
};
// @lc code=end

