/*
 * @lc app=leetcode id=99 lang=cpp
 *
 * [99] Recover Binary Search Tree
 *
 * https://leetcode.com/problems/recover-binary-search-tree/description/
 *
 * algorithms
 * Hard (39.90%)
 * Likes:    1688
 * Dislikes: 77
 * Total Accepted:    170.9K
 * Total Submissions: 428.3K
 * Testcase Example:  '[1,3,null,null,2]'
 *
 * Two elements of a binary search tree (BST) are swapped by mistake.
 * 
 * Recover the tree without changing its structure.
 * 
 * Example 1:
 * 
 * 
 * Input: [1,3,null,null,2]
 * 
 * 1
 * /
 * 3
 * \
 * 2
 * 
 * Output: [3,1,null,null,2]
 * 
 * 3
 * /
 * 1
 * \
 * 2
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: [3,1,4,null,null,2]
 * 
 * ⁠ 3
 * ⁠/ \
 * 1   4
 * /
 * 2
 * 
 * Output: [2,1,4,null,null,3]
 * 
 * ⁠ 2
 * ⁠/ \
 * 1   4
 * /
 * ⁠ 3
 * 
 * 
 * Follow up:
 * 
 * 
 * A solution using O(n) space is pretty straight forward.
 * Could you devise a constant space solution?
 * 
 * 
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
    void recoverTree(TreeNode* root) {
        createTree(root);
        TreeNode* tem = root;
        TreeNode* temswap = root;
        long lastval = LONG_MIN;
        bool firstError = true;
        while (tem->left != NULL)
        {
            tem = tem->left;
        }
        while (tem->right != NULL)
        {
            if ((tem->val > lastval && tem->val >= tem->right->val) || (tem->val <= lastval && tem->val < tem->right->val))
            {
                if (firstError)
                {
                    temswap = tem;
                    firstError = false;
                }
                else
                {
                    swap(temswap->val, tem->val);
                    firstError = true;
                    break;
                }
            }
            lastval = tem->val;
            tem = tem->right;
        }
        if (!firstError)
        {
            swap(temswap->val, tem->val);
        }
        createTree2(root);
    }
    void createTree(TreeNode* root){
        if (root == NULL || root->left == NULL)
        {
            return;
        }
        
        modifyRightTree(root);
        createTree(root->left);
        createTree(root->right);
    }
    void modifyRightTree(TreeNode* root){
        TreeNode* tem = root->left;
        while (tem->right != NULL)
        {
            tem = tem->right;
            if (tem->val == root->val)
            {
                return;
            }
        }
        tem->right = root;
    }
    void createTree2(TreeNode* root){
        if (root == NULL || root->left == NULL)
        {
            return;
        }
        
        modifyRightTree2(root);
        createTree2(root->left);
        createTree2(root->right);
    }
    void modifyRightTree2(TreeNode* root){
        TreeNode* tem = root->left;
        while (tem->right != NULL)
        {
            if (tem->right->val == root->val)
            {
                tem->right = NULL;
                return;
            }
            tem = tem->right;
        }
        tem->right = root;
    }
};
// @lc code=end

