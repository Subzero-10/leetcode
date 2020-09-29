/*
 * @lc app=leetcode id=160 lang=cpp
 *
 * [160] Intersection of Two Linked Lists
 */

// @lc code=start
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode * temA = headA;
        ListNode * temB = headB;
        while (temA && temB)
        {
            temA = temA->next;
            temB = temB->next;
        }
        if (temA)
        {
            temB = headA;
            while (temA)
            {
                temA = temA->next;
                temB = temB->next;
            }
            temA = headB;
        }
        else
        {
            temA = headB;
            while (temB)
            {
                temA = temA->next;
                temB = temB->next;
            }
            temB = headA;
        }
        while (temA && temB)
        {
            if (temA==temB)
            {
                return temA;
            }
            temA = temA->next;
            temB = temB->next;
        }
        return NULL;
    }
};
// @lc code=end

