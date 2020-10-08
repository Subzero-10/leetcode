/*
 * @lc app=leetcode id=173 lang=cpp
 *
 * [173] Binary Search Tree Iterator
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
class BSTIterator {
public:
    BSTIterator(TreeNode* root) {
        bool isfirst = true;
        while (root)
        {
            TreeNode* tem = root->left;
            if (!tem)
            {
                if (isfirst)
                {
                    firstnode = root;
                    isfirst = false;
                }
                root = root->right;
            }
            else
            {
                bool again = false;
                while (tem->right)
                {
                    tem = tem->right;
                    if (tem == root)
                    {
                        again = true;
                        break;
                    }
                }
                if (!again)
                {
                    tem->right = root;
                    root = root->left;
                }
                else
                {
                    root = root->right;
                }
            }
        }
    }
    TreeNode* firstnode;
    /** @return the next smallest number */
    int next() {
        int a = firstnode->val;
        TreeNode* tem = firstnode->right;
        bool isfind = false;
        while (tem&&tem->left)
        {
            tem = tem->left;
            if (tem == firstnode)
            {
                firstnode = firstnode->right;
                isfind = true;
                break;
            }
        }
        if (!isfind)
        {
            firstnode = firstnode->right;
            while (firstnode&&firstnode->left)
            {
                firstnode = firstnode->left;
            }
        }
        return a;
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        if (firstnode)
        {
            return true;
        }
        return false;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */
// @lc code=end

