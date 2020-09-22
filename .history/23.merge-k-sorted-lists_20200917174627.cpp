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
        priority_queue<pair<int, ListNode *>, vector<pair<int, ListNode *>>, greater<int> > q;
        for(int i; i<(int)lists.size(); i++){
            if(lists[i]!=NULL){
                q.push(pair<int, ListNode *>(lists[i]->val,lists[i]));
            }
        }
        ListNode * output = new ListNode(0);
        while(!q.empty()){
            ListNode * nextnode = q.top().second;
            output->next = nextnode;
            q.pop();
            if(nextnode->next){
                q.push(pair<int, ListNode *>(nextnode->next->val,nextnode->next));
            }
        }
        return output->next;
    }
};
// @lc code=end

