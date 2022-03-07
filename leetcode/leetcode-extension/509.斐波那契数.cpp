/*
 * @lc app=leetcode.cn id=509 lang=cpp
 *
 * [509] 斐波那契数
 */

// @lc code=start
#include <vector>

using std::vector;
// 动态规划-自底向上
// 0 1 1 2 3 5 8

class Solution {
 public:
  // int fib(int n) {
  //   if (n < 2)
  //     return n;

  //   // 使用dp的思想，不过只需要维护两个数值就可以了，不需要记录整个序列
  //   // 所以使用prev、curr替代 dp[0] dp[1]
  //   int prev = 0;
  //   int curr = 1;

  //   // 注意循环次数n-1
  //   for (int i = 0; i < n-1 ; ++i) {
  //     int tmp  = curr;  // 注意由于curr值要更新，所以需要用一个tmp值缓存一下
  //     curr = prev + curr; // 本轮的curr等于前两个数字相加 dp[i] = dp[i-1] +
  //     dp[i-2] prev = tmp; // 更新prev为上一轮的curr

  //   }
  //   return curr;
  // }

  // f(n) = f(n-1) + f(n-2)

  /* fib 传统动态规划版本 */
  /* int fib(int n) {
    if (n < 2)
      return n;

    vector<int> dp(n + 1, 0);
    dp[0] = 0;
    dp[1] = 1;

    for (int i = 2; i < n + 1; i++) {
      dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
  } */

  /* fib 动态规划优化版本 */
  int fib(int n) {
    // 0 1 1 2 3
    if (n < 2)
      return n;

    int prev = 0, curr = 1;
    int tmp = 0;

    for (int i = 2; i < n + 1; i++) { // 这里的初始化为2，代表的是此轮的数字下标，所以结束标志为n+1
      tmp = prev;
      prev = curr;
      curr = tmp + curr;
    }
    return curr;
  }
};
// @lc code=end
