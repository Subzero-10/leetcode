/*
 * @lc app=leetcode id=147 lang=cpp
 *
 * [147] Insertion Sort List
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
    ListNode* insertionSortList(ListNode* head) {
        ListNode* endnode = head;
        ListNode* headnode = new ListNode(0,head);
        while (endnode!=NULL && endnode->next!=NULL)
        {
            ListNode* tem = endnode->next;
            ListNode* temn = tem->next;
            if (tem->val < endnode->val)
            {
                ListNode* tempre = headnode;
                while (tempre->next->val < tem->val)
                {
                    tempre = tempre->next;
                }
                ListNode* temnext = tempre->next;
                tempre->next = tem;
                tem->next = temnext;
                endnode->next = temn;
            }
            else
            {
                endnode = endnode->next;
            }
        }
        return headnode->next;
    }
};
// @lc code=end

