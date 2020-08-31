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
        TreeNode* swapNode1 = new TreeNode();
        TreeNode* swapNode2 = new TreeNode();
        createTree(root, swapNode1, swapNode2);
        if(swapNode2->right == NULL)
        {
            swap(swapNode1->left->val, swapNode1->right->val);
        }
        else
        {
            swap(swapNode1->left->val, swapNode2->right->val);
        }
    }
    void createTree(TreeNode* root, TreeNode* swapNode1, TreeNode* swapNode2){
        if (root->left == NULL)
        {
            swapNode(root, swapNode1, swapNode2);
            return;
        }
        printf("1");
        modifyRightTree(root, swapNode1, swapNode2);
        printf("1");
        createTree(root->left, swapNode1, swapNode2);
        createTree(root->right, swapNode1, swapNode2);
    }
    void modifyRightTree(TreeNode* root, TreeNode* swapNode1, TreeNode* swapNode2){
        TreeNode* tem = root->left;
        while (tem->right != NULL)
        {
            if (tem->right->val == root->val)
            {
                swapNode(root, swapNode1, swapNode2);
                tem->right = NULL;
                return;
            }
            tem = tem->right;
        }
        tem->right = root;
    }
    void swapNode(TreeNode* root, TreeNode* swapNode1, TreeNode* swapNode2)
    {
        if (swapNode1->left != NULL && swapNode1->right == NULL)
        {
            if (swapNode1->left->val > root->val)
            {
                swapNode1->right = root;
                swapNode2->left = root;
            }
            else
            {
                swapNode1->left = root;
            }
        }
        else if (swapNode1->left == NULL)
        {
            swapNode1->left = root;
        }
        else if (swapNode2->right == NULL)
        {
            if (swapNode2->left->val > root->val)
            {
                swapNode2->right = root;
                return;
            }
            else
            {
                swapNode2->left = root;
            }
        }
    }
};
// @lc code=end

