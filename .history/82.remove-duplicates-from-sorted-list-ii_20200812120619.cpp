/*
 * @lc app=leetcode id=82 lang=cpp
 *
 * [82] Remove Duplicates from Sorted List II
 *
 * https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/description/
 *
 * algorithms
 * Medium (35.43%)
 * Likes:    1786
 * Dislikes: 110
 * Total Accepted:    256.2K
 * Total Submissions: 696.6K
 * Testcase Example:  '[1,2,3,3,4,4,5]'
 *
 * Given a sorted linked list, delete all nodes that have duplicate numbers,
 * leaving only distinct numbers from the original list.
 * 
 * Return the linked list sorted as well.
 * 
 * Example 1:
 * 
 * 
 * Input: 1->2->3->3->4->4->5
 * Output: 1->2->5
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 1->1->1->2->3
 * Output: 2->3
 * 
 * 
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
    ListNode* deleteDuplicates(ListNode* head) {
        ListNode* output = new ListNode;
        ListNode* outputhead = output;
        ListNode* now = new ListNode(0,head);
        if (now->next == NULL || now->next->next == NULL)
        {
            return outputhead->next;
        }
        if (now->next->val != now->next->next->val)
        {
            output->next = now->next;
            output = output->next;
        }
        
        while (now->next->next != NULL && now->next != NULL && now->next->next->next != NULL)
        {
            printf("%d,%d,%d\n",now->next->val,now->next->next->val,now->next->next->next->val);
            if (now->next->next->val != now->next->val && now->next->next->val != now->next->next->next->val)
            {
                output->next = now->next->next;
                output = output->next;
            } 
            now = now->next;
        }
        return outputhead->next;
    }
};
// @lc code=end

