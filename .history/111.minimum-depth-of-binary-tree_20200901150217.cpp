/*
 * @lc app=leetcode id=111 lang=cpp
 *
 * [111] Minimum Depth of Binary Tree
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
    int minDepth(TreeNode* root) {
        queue<TreeNode*> q;
        if (root!=NULL)
        {
            q.push(root);
        }
        int len;
        bool stop = false;
        int i  = 0;
        while (!q.empty())
        {
            len = q.size();
            i++;
            for (int i = 0; i < len; i++)
            {
                if (q.front()->left != NULL)
                {
                    q.push(q.front()->left);
                }
                if (q.front()->right != NULL)
                {
                    q.push(q.front()->right);
                }
                if ((q.front()->right == NULL)&&(q.front()->left == NULL))
                {
                    stop = true;
                }
                q.pop();
            }
            if (stop)
            {
                break;
            }
        }
        return i;
    }
};
// @lc code=end

