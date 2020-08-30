/*
 * @lc app=leetcode id=24 lang=cpp
 *
 * [24] Swap Nodes in Pairs
 *
 * https://leetcode.com/problems/swap-nodes-in-pairs/description/
 *
 * algorithms
 * Medium (48.49%)
 * Likes:    1895
 * Dislikes: 158
 * Total Accepted:    430K
 * Total Submissions: 880.5K
 * Testcase Example:  '[1,2,3,4]'
 *
 * Given a linked list, swap every two adjacent nodes and return its head.
 * 
 * You may not modify the values in the list's nodes, only nodes itself may be
 * changed.
 * 
 * 
 * 
 * Example:
 * 
 * 
 * Given 1->2->3->4, you should return the list as 2->1->4->3.
 * 
 * 
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
    ListNode* swapPairs(ListNode* head) {
        ListNode* p = new ListNode;
        ListNode* swapP = new ListNode;
        ListNode* headP = new ListNode;
        ListNode* lastP = new ListNode;
        p = head;
        headP->next = p;
        lastP = headP;
        while (p != NULL && p->next != NULL)
        {
            /* code */
            swapP = p->next;
            p->next = swapP->next;
            swapP->next = p;
            lastP->next = swapP;
            lastP = p; 
            p = p->next;
        }
        
        return headP->next;
    }
};
// @lc code=end

