/*
 * @lc app=leetcode id=61 lang=cpp
 *
 * [61] Rotate List
 *
 * https://leetcode.com/problems/rotate-list/description/
 *
 * algorithms
 * Medium (28.98%)
 * Likes:    1284
 * Dislikes: 1010
 * Total Accepted:    278K
 * Total Submissions: 928.6K
 * Testcase Example:  '[1,2,3,4,5]\n2'
 *
 * Given a linked list, rotate the list to the right by k places, where k is
 * non-negative.
 * 
 * Example 1:
 * 
 * 
 * Input: 1->2->3->4->5->NULL, k = 2
 * Output: 4->5->1->2->3->NULL
 * Explanation:
 * rotate 1 steps to the right: 5->1->2->3->4->NULL
 * rotate 2 steps to the right: 4->5->1->2->3->NULL
 * 
 * 
 * Example 2:
 * 
 * 
 * Input: 0->1->2->NULL, k = 4
 * Output: 2->0->1->NULL
 * Explanation:
 * rotate 1 steps to the right: 2->0->1->NULL
 * rotate 2 steps to the right: 1->2->0->NULL
 * rotate 3 steps to the right: 0->1->2->NULL
 * rotate 4 steps to the right: 2->0->1->NULL
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
    ListNode* rotateRight(ListNode* head, int k) {
        bool isnull = false;
        int len = 1;
        ListNode* nextpos = head;
        ListNode* lastpos = head;
        while (!isnull)
        {
            if (nextpos->next != NULL)
            {
                len++;
                nextpos = nextpos->next;
            }
            else
            {
                lastpos = nextpos;
                isnull = true;
            }
        }
        int n = len - k%len;
        if (n==0)
        {
            return head;
        }
        nextpos = head;
        for (int i = 1; i < n; i++)
        {
            nextpos = nextpos->next;
        }
        ListNode* headpos = nextpos->next;
        ListNode* outputhead = new ListNode(0,headpos);
        lastpos->next = head;
        nextpos->next = NULL;
        return outputhead->next;
    }
};
// @lc code=end

