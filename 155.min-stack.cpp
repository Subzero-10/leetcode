/*
 * @lc app=leetcode id=155 lang=cpp
 *
 * [155] Min Stack
 */

// @lc code=start
class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> s;
    map<int,int> m;
    MinStack() {
    }
    
    void push(int x) {
        s.push(x);
        m[x]++;
    }
    
    void pop() {
        int x = s.top();
        s.pop();
        m[x]--;
        if (m[x] == 0)
        {
            m.erase(x);
        }
    }
    
    int top() {
        return s.top();
    }
    
    int getMin() {
        map<int,int>::iterator it = m.begin();
        return it->first;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */
// @lc code=end

