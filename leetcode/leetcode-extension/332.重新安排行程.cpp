/*
 * @lc app=leetcode.cn id=332 lang=cpp
 *
 * [332] 重新安排行程
 */
#include <string>
#include <vector>

using std::string;
using std::vector;

// @lc code=start

class place {
  string from;
  string to;
  place* next;
  place(string from, string to) : from(from), to(to), next(nullptr){};
};

class Solution {
 public:
  void backtrack() {}
  vector<string> findItinerary(vector<vector<string>>& tickets) {}
};
// @lc code=end
