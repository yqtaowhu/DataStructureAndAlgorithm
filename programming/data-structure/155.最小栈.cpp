/*
 * @lc app=leetcode.cn id=155 lang=cpp
 *
 * [155] 最小栈
 */

// @lc code=start
class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> s1, s2;
    MinStack() {

    }
    
    void push(int x) {
        // s1正常操作，s2存储最小值
        s1.push(x);
        if(s2.empty() || x <= getMin()) {
            s2.push(x);
        }
    }
    
    void pop() {
        // 要判断是否对s2进行pop
        if(s1.top() == s2.top()) {
            s2.pop();
        }
        s1.pop();
    }
    
    int top() {
        return s1.top();
    }
    
    int getMin() {
        return s2.top();
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

