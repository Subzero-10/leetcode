/*
 * @lc app=leetcode id=143 lang=cpp
 *
 * [143] Reorder List
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
class Solution {
public:
    void reorderList(ListNode* head) {
        stack<ListNode*> s;
        ListNode* root = head;
        while (root)
        {
            s.push(root);
            root = root->next;
        }
        root = head;
        while (root->next && (root->next != s.top()))
        {
            printf("%d",s.top()->val);
            ListNode* tem = root->next;
            root->next = s.top();
            s.top()->next = tem;
            s.pop();
            root = tem;
        }
    }
};
// @lc code=end

