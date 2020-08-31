/*
 * @lc app=leetcode id=105 lang=cpp
 *
 * [105] Construct Binary Tree from Preorder and Inorder Traversal
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() == 0)
        {
            return NULL;
        }
        TreeNode* root = new TreeNode(preorder[0]);
        int i = 0;
        for (i = 0; i < (int)inorder.size(); i++)
        {
            if (inorder[i] == preorder[0])
            {
                break;
            }
        }
        vector<int> test(preorder.end(),preorder.end());
        printf("test:%d",(int)test.size());
        vector<int> preleft(preorder.begin()+1, preorder.begin()+1+i);
        vector<int> inleft(inorder.begin(), inorder.begin()+i);
        vector<int> preright(preorder.begin()+1+i, preorder.end());
        vector<int> inright(inorder.begin()+1+i, inorder.end());
        root->left = buildTree(preleft, inleft);
        root->right = buildTree(preright, inright);
        return root;
    }
};
// @lc code=end

