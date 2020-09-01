/*
 * @lc app=leetcode id=109 lang=cpp
 *
 * [109] Convert Sorted List to Binary Search Tree
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> nums;
        while (head != NULL)
        {
            nums.push_back(head->val);
            head = head->next;
        }
        return sortedArrayToBST(nums);
    }
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

