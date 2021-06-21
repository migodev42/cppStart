/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原 IP 地址
 */
#include <string>
#include <vector>

using std::stoi;
using std::stoll;
using std::string;
using std::vector;
// @lc code=start
class Solution {
 public:
  vector<string> result;
  vector<string> path;
  string convertPathToStr(vector<string> target) {
    string rs;
    for (int i = 0; i < path.size(); ++i) {
      if (i == path.size() - 1) {
        rs += path[i];
      } else {
        rs += path[i] + ".";
      }
    }
    return rs;
  }
  void backtrack(string s, int splitidx) {
    if (splitidx >= s.size() && path.size() == 4) {
      string rs = convertPathToStr(path);
      result.push_back(rs);
      return;
    }

    for (int i = splitidx; i < s.size(); ++i) {
      if (i - splitidx < 3 && path.size() < 4) {
        string str = s.substr(splitidx, i - splitidx + 1);
        if (str.size() > 1 && str[0] == '0')
          continue;

        int curr = stoi(str);
        if (curr <= 255) {
          path.push_back(str);
        } else {
          continue;
        }

      } else {
        continue;
      }
      backtrack(s, i + 1);
      path.pop_back();
    }
  }
  vector<string> restoreIpAddresses(string s) {
    backtrack(s, 0);
    return result;
  }
};
// @lc code=end

int main() {
  Solution s;
  string target = "25525511135";
  s.restoreIpAddresses(target);
  return 0;
}