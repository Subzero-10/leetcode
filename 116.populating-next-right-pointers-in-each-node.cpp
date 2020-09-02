/*
 * @lc app=leetcode id=116 lang=cpp
 *
 * [116] Populating Next Right Pointers in Each Node
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
        queue<Node*> q;
        if (root != NULL)
        {
            q.push(root);
        }
        int len;
        while (!q.empty())
        {
            len = (int)q.size();
            Node* tem = new Node();
            for (int i = 0; i < len; i++)
            {
                tem = q.front();
                q.pop();
                tem->next = q.front();
                if (tem->left != NULL)
                {
                    q.push(tem->left);
                }
                if (tem->right != NULL)
                {
                    q.push(tem->right);
                }
            }
            tem->next = NULL;
        }
        return root;
    }
};
// @lc code=end

