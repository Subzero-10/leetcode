/*
 * @lc app=leetcode id=138 lang=cpp
 *
 * [138] Copy List with Random Pointer
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* root = head;
        while (!head)
        {
            Node* newHead = new Node(head->val);
            newHead->next = head->next;
            head->next = newHead;
            head = newHead->next;
        }
        head = root;
        root = root->next;
        printf("%d",root->val);
        while (!head)
        {
            Node* newHead = head->next;
            newHead->random = head->random->next;
            head->next =  newHead->next;
            newHead->next = newHead->next->next;
            head = head->next;
        }
        return root;
    }
};
// @lc code=end

