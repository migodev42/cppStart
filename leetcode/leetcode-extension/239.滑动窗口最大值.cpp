/*
 * @lc app=leetcode.cn id=239 lang=cpp
 *
 * [239] 滑动窗口最大值
 */
#include <deque>
#include <vector>

using std::deque;
using std::vector;

// @lc code=start
class Solution {
   private:
    class MyQue {
       public:
        deque<int> que; // 使用deque来实现单调(递减)队列
        // pop之前判断队列当前是否为空。
        // 每次弹出的时候，比较当前要弹出的数值是否等于队列出口元素的数值，如果相等则弹出。
        void pop(int value) {
            if (!que.empty() && value == que.front()) {
                que.pop_front();
            }
        }

        // 如果push的数值大于入口元素的数值，那么就将队列后端的数值弹出，直到push的数值小于等于队列入口元素的数值为止。 
        // 这样就保持了队列里的数值是单调从大到小的了。
        void push(int value) {
            while (!que.empty() && value > que.back()) {
                que.pop_back();
            }
            que.push_back(value);
        }
        // 查询当前队列里的最大值 直接返回队列前端也就是front就可以了。
        int front() { return que.front(); }
    };

   public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        MyQue que;// 维护一个单调递减队列，在窗口滑动时推出和推入都保持队列的单调
                  // 则队列最前端的值，即为滑动窗口的最大值
        vector<int> result;
        for (int i=0; i < k; ++i) {
            que.push(nums[i]);
        }
        result.push_back(que.front());
        for (int i = k; i < nums.size(); ++i) {
            que.pop(nums[i - k]);
            que.push(nums[i]);
            result.push_back(que.front());
        }
        return result;
    }
};
// @lc code=end
