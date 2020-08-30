/*
 * @lc app=leetcode id=95 lang=cpp
 *
 * [95] Unique Binary Search Trees II
 *
 * https://leetcode.com/problems/unique-binary-search-trees-ii/description/
 *
 * algorithms
 * Medium (38.68%)
 * Likes:    2375
 * Dislikes: 161
 * Total Accepted:    199.2K
 * Total Submissions: 488.2K
 * Testcase Example:  '3'
 *
 * Given an integer n, generate all structurally unique BST's (binary search
 * trees) that store values 1 ... n.
 * 
 * Example:
 * 
 * 
 * Input: 3
 * Output:
 * [
 * [1,null,3,2],
 * [3,2,null,1],
 * [3,1,null,null,2],
 * [2,1,3],
 * [1,null,2,null,3]
 * ]
 * Explanation:
 * The above output corresponds to the 5 unique BST's shown below:
 * 
 * ⁠  1         3     3      2      1
 * ⁠   \       /     /      / \      \
 * ⁠    3     2     1      1   3      2
 * ⁠   /     /       \                 \
 * ⁠  2     1         2                 3
 * 
 * 
 * 
 * Constraints:
 * 
 * 
 * 0 <= n <= 8
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
    vector<TreeNode*> generateTrees(int n) {
        vector<TreeNode*> output;
        for (int i = 1; i <= n; i++)
        {
            TreeNode* tem = new TreeNode(i);
            helper(tem,1,i-1,output,i,n,1);
            helper(tem,i+1,n,output,i,n,i);
        }
        output[0]->val = 9;
        return output;
    }
    void helper(TreeNode* lastHead, int left, int right, vector<TreeNode*>& output, int val,int n,int step){
        if (left>right)
        {
            return;
        }
        TreeNode* newHead = new TreeNode();
        TreeNode* lastNode = copyTree(lastHead, newHead, val);
        for (int i = left; i <= right; i++)
        {
            TreeNode* tem = new TreeNode(i);
            if (right<val)
            {
                lastNode->left = tem;
            }
            else
            {
                lastNode->right = tem;
            }
            if (step == n-1)
            {
                output.push_back(lastHead);
                printf("%d\n",lastHead);
            }
            helper(newHead,left,i-1,output,i,n,step+1);
            helper(newHead,i+1,right,output,i,n,step+i-left+1);
        }
    }
    TreeNode* copyTree(TreeNode* oldTree, TreeNode* newTree, int val){
        TreeNode* lastNode = new TreeNode(val);
        newTree->val = oldTree->val;
        copyNode(oldTree, newTree, val, lastNode);
        return lastNode;
    }
    void copyNode(TreeNode* oldNode, TreeNode* newNode, int val, TreeNode* lastNode){
        if (oldNode == NULL)
        {
            return;
        }
        if (oldNode->val == val)
        {
            newNode = lastNode;
        }
        if (oldNode->left != NULL)
        {
            newNode->left = new TreeNode(oldNode->left->val);
        }
        if (oldNode->right != NULL)
        {
            newNode->right = new TreeNode(oldNode->right ->val);
        }
        copyNode(oldNode->left, newNode->left, val, lastNode);
        copyNode(oldNode->right, newNode->right, val, lastNode);
    }

};
// @lc code=end

