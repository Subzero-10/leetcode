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
        while (head2)
        {
            Node* newHead = head2->next;
            if (head2->random)
            {
                newHead->random = head2->random->next;
            }
            else
            {
                newHead->random = NULL;
            }
            head2 = head2->next;
        }
        printf("?");
        Node* head3 = root;
        root = root->next;
        while (head3)
        {
            Node* newHead = head3->next;
            head3->next = newHead->next;
            if (head3->next)
            {
                newHead->next = head3->next->next;
            }
            else
            {
                newHead->next = NULL;
            }
            head3 = head3->next;
        }
        return root;
    }
};
// @lc code=end

