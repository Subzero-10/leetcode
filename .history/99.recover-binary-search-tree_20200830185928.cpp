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
        queue<TreeNode*> q;
        TreeNode* swapNode = new TreeNode();
        helper(root, q, swapNode);
        if (swapNode->right == NULL)
        {
            swapNode->right = q.back();
        }
        swap(swapNode->left->val, swapNode->right->val);
    }
    void helper(TreeNode* root, queue<TreeNode*>& q, TreeNode* swapNode){
        if (swapNode->right != NULL)
        {
            return;
        }
        
        if (root != NULL)
        {
            helper(root->left, q, swapNode);
            if (q.size() == 0)
            {
                q.push(root);
            }
            else if (q.size() == 1)
            {
                if (q.front()->val >= root->val)
                {
                    swapNode->left = q.front();
                }
                q.push(root);
            }
            else
            {
                TreeNode* tem = q.front();
                q.pop();
                TreeNode* tem2 = q.front();
                if ((tem->val >= tem2->val && tem2->val < root->val)||(tem->val < tem2->val && tem2->val >= root->val))
                {
                    if (swapNode->left != NULL)
                    {
                        swapNode->right = tem2;
                        return;
                    }
                    else
                    {
                        swapNode->left = tem2;
                    }
                }
                q.push(root);
            }
            helper(root->right, q, swapNode);
        }
    }
};
// @lc code=end

