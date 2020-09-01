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
        if (head == NULL)
        {
            return NULL;
        }
        ListNode* fast = head;
        ListNode* slow = head;
        ListNode* slowlast = head;
        while (fast->next != NULL && fast->next->next != NULL)
        {
            slowlast = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        TreeNode* root = new TreeNode(slow->val);
        if (slow == head)
        {
            root->left = NULL;
            root->right = sortedListToBST(slow->next);
        }
        else
        {
            slowlast->next = NULL;
            root->left = sortedListToBST(head);
            root->right = sortedListToBST(slow->next);
        }
        return root;
    }
};
// @lc code=end

