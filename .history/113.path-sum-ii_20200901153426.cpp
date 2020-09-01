/*
 * @lc app=leetcode id=113 lang=cpp
 *
 * [113] Path Sum II
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
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        return helper(root, sum, 0);
    }
    vector<vector<int>> helper(TreeNode* root, int sum, int nowsum){
        vector<vector<int>> output;
        if (root == NULL)
        {
            return output;
        }
        nowsum += root->val;
        if (root->left == NULL && root->right== NULL)
        {
            if (sum == nowsum)
            {
                vector<int> tem(root->val);
                output.push_back(tem);
            }
            return output;
        }
        vector<vector<int>> outputleft(helper(root->left, sum, nowsum).begin(), helper(root->left, sum, nowsum).end());
        vector<vector<int>> outputright(helper(root->right, sum, nowsum).begin(), helper(root->right, sum, nowsum).end());
        vector<vector<int>>::iterator it;
        for (it = outputleft.begin(); it != outputleft.end(); it++)
        {
            *it->push_back(root->val);
            output.push_back(*it);
        }
        for (it = outputright.begin(); it != outputright.end(); it++)
        {
            *it->push_back(root->val);
            output.push_back(*it);
        }
        return output;
    }
};
// @lc code=end

