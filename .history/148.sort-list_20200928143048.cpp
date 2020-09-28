/*
 * @lc app=leetcode id=148 lang=cpp
 *
 * [148] Sort List
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
    ListNode* mergeList(ListNode* slow, ListNode* fast){

        ListNode* head = new ListNode();
        ListNode* output; = head;
        while (slow&&fast)
        {
            if (slow->val<=fast->val)
            {
                head->next = slow;
                head = head->next;
                slow = slow->next;
                head->next = NULL;
            }
            else
            {
                head->next = fast;
                head = head->next;
                fast = fast->next;
                head->next = NULL;
            }
        }
        if (slow)
        {
            head->next = slow;
        }
        if (fast)
        {
            head->next = fast;
        }
        return output;
    }
    ListNode* sortList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head->next;
        if (!fast)
        {
            return head;
        }
        while (fast->next && fast->next->next)
        {
            slow = slow->next;
            fast = fast->next->next;
        }
        fast = sortList(slow->next);
        slow->next = NULL;
        slow = sortList(head);
        return mergeList(slow,fast);
    }
};
// @lc code=end

