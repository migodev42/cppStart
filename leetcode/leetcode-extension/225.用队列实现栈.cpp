/*
 * @lc app=leetcode.cn id=225 lang=cpp
 *
 * [225] 用队列实现栈
 */
#include <queue>

using std::queue;

// @lc code=start
class MyStack {
   public:
    queue<int> qIn;
    queue<int> qMemo; /* 辅助队列，用于备份 */
    /** Initialize your data structure here. */
    MyStack() {}

    /** Push element x onto stack. */
    void push(int x) { qIn.push(x); }

    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int size = qIn.size() - 1;  // 留队列尾下一个元素，即为pop的元素
        while (size--) {
            int value = qIn.front();
            qIn.pop();
            qMemo.push(value);
        }
        int value = qIn.front();
        qIn.pop();
        qIn = qMemo;
        while(!qMemo.empty()){
          qMemo.pop();
        }
        return value;
    }

    /** Get the top element. */
    int top() {
      return qIn.back();
    }

    /** Returns whether the stack is empty. */
    bool empty() {
      return qIn.empty();
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
// @lc code=end
