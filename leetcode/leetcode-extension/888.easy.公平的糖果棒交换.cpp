/*
 * @lc app=leetcode.cn id=888 lang=cpp
 *
 * [888] 公平的糖果棒交换
 */

// @lc code=start
#include <vector>
#include <unordered_set>
using std::unordered_set;
using std::vector;
// Hash法
// 时间复杂度：O(n + m)O(n+m)，其中 nn 是序列 AA 的长度，mm 是序列 BB 的长度。
// 空间复杂度：O(n)O(n)，其中 nn 是序列 AA 的长度。我们需要建立一个和序列 AA 等大的哈希表
class Solution {
public:
  vector<int> fairCandySwap(vector<int>& A, vector<int>& B) {
    int Atotal = 0;
    int Btotal = 0;
    for (auto a : A) {
      Atotal += a;
    }
    for (auto b : B) {
      Btotal += b;
    }
    unordered_set<int> memo(A.begin(), A.end());

    for (int j = 0; j < B.size(); ++j) {
      // Atotal -A[i] + B[j] == Btotal - B[j] + A[i];
      // 2A[i] == Atotal - Btotal  + 2 * B[j]
      // A[i] = (Atotal - Btotal)/2 + B[j]
      auto search = memo.find((Atotal - Btotal)/2 + B[j]);
      if (search != memo.end()) return { *search, B[j] };
    }
    return vector<int>();
  }
};
// @lc code=end

