/*
 * @lc app=leetcode id=86 lang=cpp
 *
 * [86] Partition List
 *
 * https://leetcode.com/problems/partition-list/description/
 *
 * algorithms
 * Medium (39.90%)
 * Likes:    1379
 * Dislikes: 305
 * Total Accepted:    221K
 * Total Submissions: 531.8K
 * Testcase Example:  '[1,4,3,2,5,2]\n3'
 *
 * Given a linked list and a value x, partition it such that all nodes less
 * than x come before nodes greater than or equal to x.
 * 
 * You should preserve the original relative order of the nodes in each of the
 * two partitions.
 * 
 * Example:
 * 
 * 
 * Input: head = 1->4->3->2->5->2, x = 3
 * Output: 1->2->2->4->3->5
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
    ListNode* partition(ListNode* head, int x) {
        ListNode* output = new ListNode(0,head);
        ListNode* left = output;
        ListNode* right = output;
        ListNode* now = head;
        while (now == NULL)
        {
            if (now->val < x)
            {
                if (right == output)
                {
                    left = now;
                    now = now->next;
                    printf("%d",now->val);
                }
                else
                {
                    ListNode* tem = left->next;
                    left->next = now;
                    left = left->next;
                    now = now->next;
                    left->next = tem;
                    right->next = now;
                }
            }
            else
            {
                right = now;
                now = now->next;
            }
        }
        return output->next;
    }
};
// @lc code=end

