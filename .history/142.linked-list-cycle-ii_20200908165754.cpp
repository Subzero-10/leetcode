/*
 * @lc app=leetcode id=142 lang=cpp
 *
 * [142] Linked List Cycle II
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
    ListNode *detectCycle(ListNode *head) {
        ListNode *firstNode = head;
        ListNode *secondNode = head;
        ListNode *thirdNode = head;
        while(firstNode && firstNode->next)
        {
            secondNode = secondNode->next;
            firstNode = firstNode->next->next;
            if (secondNode == firstNode)
            {
                int a = 0;
                while (thirdNode != secondNode)
                {
                    thirdNode = thirdNode->next;
                    secondNode = secondNode->next;
                    a++;
                }
                return a;
            }
        }
        return -1;
    }
};
// @lc code=end

