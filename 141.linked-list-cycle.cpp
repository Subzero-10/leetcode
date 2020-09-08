/*
 * @lc app=leetcode id=141 lang=cpp
 *
 * [141] Linked List Cycle
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
    bool hasCycle(ListNode *head) {
        if (!head)
        {
            return false;
        }
        
        while (head->next)
        {
            ListNode *nextNode = head->next;
            if (nextNode == head)
            {
                return true;
            }
            head->next = head;
            head = nextNode;
        }
        return false;
    }
};
// @lc code=end

