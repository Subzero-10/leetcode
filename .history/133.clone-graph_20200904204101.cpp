/*
 * @lc app=leetcode id=133 lang=cpp
 *
 * [133] Clone Graph
 */

// @lc code=start
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if (!node)
        {
            return NULL;
        }
        map<int,Node*> nm;
        Node* root = new Node(node.val);
        nm[node.val] = root;
        stack<Node*> s;
        s.push(node);
        while (!s.empty())
        {
            int len = s.top().neighbors.size();
            Node* thisNode = s.top();
            int val = s.top().val;
            s.pop();
            for (int i = 0; i < len; i++)
            {
                if (!nm.count(thisNode.neighbors[i].val))
                {
                    Node* newNode = new Node(thisNode.neighbors[i].val);
                    nm[thisNode.neighbors[i].val] = newNode;
                    s.push(thisNode.neighbors[i]);
                }
                nm[val].neighbors.push_back(nm[thisNode.neighbors[i].val]);
            }
        }
        return root;
    }
};
// @lc code=end

