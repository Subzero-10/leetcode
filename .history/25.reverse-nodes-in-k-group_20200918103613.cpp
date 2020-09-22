/*
 * @lc app=leetcode id=25 lang=cpp
 *
 * [25] Reverse Nodes in k-Group
 *
 * https://leetcode.com/problems/reverse-nodes-in-k-group/description/
 *
 * algorithms
 * Hard (39.81%)
 * Likes:    1821
 * Dislikes: 344
 * Total Accepted:    244.5K
 * Total Submissions: 608.8K
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * Given a linked list, reverse the nodes of a linked list k at a time and
 * return its modified list.
 * 
 * k is a positive integer and is less than or equal to the length of the
 * linked list. If the number of nodes is not a multiple of k then left-out
 * nodes in the end should remain as it is.
 * 
 * 
 * 
 * 
 * Example:
 * 
 * Given this linked list: 1->2->3->4->5
 * 
 * For k = 2, you should return: 2->1->4->3->5
 * 
 * For k = 3, you should return: 3->2->1->4->5
 * 
 * Note:
 * 
 * 
 * Only constant extra memory is allowed.
 * You may not alter the values in the list's nodes, only nodes itself may be
 * changed.
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
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* firstHead = new ListNode;
        ListNode* lastHead = new ListNode;
        ListNode* kNode[k+1];
        firstHead->next = head;
        lastHead = firstHead;
        while (1)
        {
            for (int i = 0; i < k+1; i++)
            {
                if (lastHead == NULL)
                {
                    return firstHead->next;
                }
                kNode[i] = lastHead;
                lastHead = lastHead->next;
            }
            for (int i = 0; i < k; i++)
            {
                ListNode* p = new ListNode;
                p = kNode[k-i];
                p->next = kNode[k-i-1];
            }
            kNode[1]->next = lastHead;
            kNode[0]->next = kNode[k];
            lastHead = kNode[1];
        }
        
    }
};
// @lc code=end

