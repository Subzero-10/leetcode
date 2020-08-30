/*
 * @lc app=leetcode id=23 lang=cpp
 *
 * [23] Merge k Sorted Lists
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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        vector <int> readyToSort;
        for (int i = 0; i < lists.size(); i++)
        {
            while (lists[i] -> next != NULL)
            {
                readyToSort.push_back(lists[i]->val);
                lists[i] = lists[i]->next;
            }
            readyToSort.push_back(lists[i]->val);
        }
        sort(readyToSort.begin(), readyToSort.end());
        ListNode outputHead = (ListNode)malloc(sizeof(Node));
        ListNode output = outputHead;       
        output->val = readyToSort[0];
        for (int i = 1; i < readyToSort.size(); i++)
        {
            ListNode* p = (ListNode)malloc(sizeof(Node));
            p->val = readyToSort[i];
            output->next = p;
            output = p;
        }
        return outputhead;
    }
};
// @lc code=end

