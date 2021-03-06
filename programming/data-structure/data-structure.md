
# 数据结构

## [两个栈实现队列](https://leetcode-cn.com/problems/yong-liang-ge-zhan-shi-xian-dui-lie-lcof/)

```
class CQueue {
public:
    stack<int> st1;
    stack<int> st2;

    CQueue() {

    }
    
    void appendTail(int value) {
        st1.push(value);
    }
    
    int deleteHead() {
        if(st2.empty()) {
            if(st1.empty())
                return -1;
            while(!st1.empty()) {
                int tmp = st1.top();
                st1.pop();
                st2.push(tmp);
            }
        }
        int res = st2.top();
        st2.pop();
        return res;
    }
};

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */
```

## [用队列实现栈](https://leetcode-cn.com/problems/implement-stack-using-queues/)
```
class MyStack {
public:
    /** Initialize your data structure here. */
    queue<int> que;
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        que.push(x);
        for(int i=0; i<que.size()-1; i++) {
            que.push(que.front());
            que.pop();
        }
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int t = que.front();
        que.pop();
        return t;
    }
    
    /** Get the top element. */
    int top() {
        return que.front();
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return que.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
```