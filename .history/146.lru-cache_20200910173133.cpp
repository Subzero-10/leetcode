/*
 * @lc app=leetcode id=146 lang=cpp
 *
 * [146] LRU Cache
 */

// @lc code=start

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class LRUCache {
public:
    LRUCache(int capacity) {
        n = capacity;
        head->right = end;
        end->left = head;
    }
    map<int, int> m;
    map<int, TreeNode*> nodem;
    int n;
    TreeNode * head = new TreeNode();
    TreeNode * end = new TreeNode();
    int get(int key) {
        if (m.count(key))
        {
            return m[key];
        }
        return -1;
    }
    
    void put(int key, int value) {
        if (m.count(key))
        {
            m[key] = value;
            TreeNode * tem2 = nodem[head->right->val];
            TreeNode * tem = nodem[key];
            tem->left->right = tem->right;
            tem->right->left = tem->left;
            tem->left = head;
            tem->right = tem2;
            tem2->left = tem;
        }
        else
        {
            int len = m.size();
            TreeNode * tem = new TreeNode(key);
            if (len < n)
            {
                m[key] = value;
                nodem[key] = tem;
                TreeNode * tem2 = head->right;
                head->right = tem;
                tem->left = head;
                tem->right = tem2;
                tem2->left = tem;
            }
            else
            {
                m[key] = value;
                nodem[key] = tem;
                int temkey = end->left->val;
                m.erase(temkey);
                end->left->left->right = end;
                end->left = end->left->left;
                nodem.erase(temkey);
                TreeNode * tem2 = head->right;
                head->right = tem;
                tem->left = head;
                tem->right = tem2;
                tem2->left = tem;
            }
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
// @lc code=end

