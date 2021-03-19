/*
 * @lc app=leetcode.cn id=232 lang=cpp
 *
 * [232] 用栈实现队列
 */
#include <stack>

using std::stack;

// @lc code=start
class MyQueue {
   public:
    stack<int> sIn;
    stack<int> sOut;
    /** Initialize your data structure here. */
    MyQueue() {}

    /** Push element x to the back of queue. */
    void push(int x) { sIn.push(x); }

    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        if (!sOut.size()) {
            while (sIn.size()) {
                int value = sIn.top();  // 取入栈顶元素
                sIn.pop();              // 删除入栈顶
                sOut.push(value);       // 推入出栈,顺序负负得正
            }
        }
        int value = sOut.top();
        sOut.pop();
        return value;
    }

    /** Get the front element. */
    int peek() {
        int value = this->pop();
        sOut.push(value);
        return value;
    }

    /** Returns whether the queue is empty. */
    bool empty() {
      return sIn.empty() && sOut.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
// @lc code=end
