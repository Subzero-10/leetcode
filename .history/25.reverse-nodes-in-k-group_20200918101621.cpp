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
        if(!head || k==1) return head;
        int n = 0;
        ListNode* root = head;
        while(root && n<k){
            root = root->next;
            n++;
        }
        if(n<k) return head;
        ListNode* end = head;
        ListNode* next = root->next;
        root->next = end;
        for(int i = 1; i<k; i++){
            ListNode* tem = end->next;
            end->next = tem->next;
            tem->next = root->next;
            root->next = tem;
        }
        printf("%d",next->val);
        end->next = reverseKGroup(next, k);
        return root;
        
    }
};
// @lc code=end

