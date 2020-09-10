/*
 * @lc app=leetcode id=146 lang=cpp
 *
 * [146] LRU Cache
 */

// @lc code=start

struct reeNode {
    int val;
    reeNode *left;
    reeNode *right;
    reeNode() : val(0), left(nullptr), right(nullptr) {}
    reeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    reeNode(int x, reeNode *left, reeNode *right) : val(x), left(left), right(right) {}
};

class LRUCache {
public:
    LRUCache(int capacity) {
        n = capacity;
        head->right = end;
        end->left = head;
    }
    map<int, int> m;
    map<int, reeNode*> nodem;
    int n;
    reeNode * head = new reeNode();
    reeNode * end = new reeNode();
    int get(int key) {
        printf("%d",key);
        if (m.count(key))
        {
            if (head->right != nodem[key])
            {
                reeNode * tem2 = head->right;
                reeNode * tem = nodem[key];
                tem->left->right = tem->right;
                tem->right->left = tem->left;
                tem->left = head;
                tem->right = tem2;
                tem2->left = tem;
            }
            printf("%d,",end->val);
            printf("%d\n",end->left->val);
            return m[key];
        }
        return -1;
    }
    
    void put(int key, int value) {
        printf("%d%d,",key,value);
        if (m.count(key))
        {
            m[key] = value;
            if (head->right != nodem[key])
            {
                reeNode * tem2 = head->right;
                reeNode * tem = nodem[key];
                tem->left->right = tem->right;
                tem->right->left = tem->left;
                tem->left = head;
                tem->right = tem2;
                tem2->left = tem;
            }
            printf("%d,",end->val);
                printf("%d\n",end->left->val);
        }
        else
        {
            int len = m.size();
            reeNode * tem = new reeNode(key);
            if (len < n)
            {
                m[key] = value;
                nodem[key] = tem;
                reeNode * tem2 = head->right;
                head->right = tem;
                tem->left = head;
                tem->right = tem2;
                tem2->left = tem;
                printf("%d,",end->val);
                printf("%d\n",end->left->val);
            }
            else
            {
                m[key] = value;
                nodem[key] = tem;
                int temkey = end->left->val;
                m.erase(temkey);
                printf("%d,",end->val);
                printf("%d,",end->left->val);
                printf("%d\n",end->left->left->val);
                end->left->left->right = end;//
                end->left = end->left->left;
                nodem.erase(temkey);
                reeNode * tem2 = head->right;
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

