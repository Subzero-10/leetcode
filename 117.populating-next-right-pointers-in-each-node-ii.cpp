/*
 * @lc app=leetcode id=117 lang=cpp
 *
 * [117] Populating Next Right Pointers in Each Node II
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        Node* dummy = new Node(0,NULL,NULL,root);
        while (dummy->next)
        {
            Node* cur = dummy->next;
            Node* pre = dummy;
            bool start = true;
            while (cur)
            {
                if (cur->left)
                {
                    if (start)
                    {
                        dummy->next = cur->left;
                        start = false;
                    }
                    pre->next = cur->left;
                    pre = cur->left;
                }
                if (cur->right)
                {
                    if (start)
                    {
                        dummy->next = cur->right;
                        start = false;
                    }
                    pre->next = cur->right;
                    pre = cur->right;
                }
                cur = cur->next;
            }
            if (start)
            {
                dummy->next = NULL;
            }
        }
        return root;
        
    }
};
// @lc code=end

