/*
 * @lc app=leetcode id=108 lang=cpp
 *
 * [108] Convert Sorted Array to Binary Search Tree
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        if (nums.empty())
        {
            return NULL;
        }
        int len = nums.size();
        TreeNode* root = new TreeNode(nums[len/2]);
        vector<int> leftnums(nums.begin(), nums.begin()+len/2);
        vector<int> rightnums(nums.begin()+len/2+1, nums.end());
        root->left = sortedArrayToBST(leftnums);
        root->right = sortedArrayToBST(rightnums);
        return root;
    }
};
// @lc code=end

