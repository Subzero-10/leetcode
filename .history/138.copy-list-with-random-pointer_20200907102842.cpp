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
        while (head)
        {
            Node* newHead = new Node(head->val);
            newHead->next = head->next;
            head->next = newHead;
            head = newHead->next;
        }
        Node* head2 = root;
        root = root->next;
        while (head2)
        {
            Node* newHead = head2->next;
            printf("?");
            newHead->random = head2->random->next;
            printf("?");
            head2->next =  newHead->next;
            printf("?");
            newHead->next = newHead->next->next;
            printf("?");
            head2 = head2->next;
            printf("?");
        }
        return root;
    }
};
// @lc code=end

