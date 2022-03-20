// https://pintia.cn/problem-sets/994805260223102976/problems/994805323154440192
/*
  规则1 PAT
  规则2 XPATX，且首尾X个数一样 APATA AAPATAA  AAAPATAAA
  规则3 当 aPbTc 正确时，aPbATca 也是正确的
  APATA 正确 APAATAA 也正确
  AAPATAA 正确 AAPAATAAAA 也正确  AAPAAATAAAAAA
  AAAPATAAA 正确 AAAPAATAAAAAA 也正确

  总结得出：c 和 a个数一致，
  b=1 a=1 c=1
  b=2 a=1 c=2
  b=3 a=1 c=3

  b=1 a=2 c=2
  b=2 a=2 c=4
  每增加一个b，即c得多加一个a

  b=1 时 a与c需要一样
  b>1 时 c= b * a

  归纳得出 b>=1 c = b * a


 */
#include <iostream>
#include <regex>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  int judge(string str) {
    smatch match_result;
    regex pat_regex = regex("^(A*|\\s*)P(A+)T(A*|\\s*)$");
    if (regex_match(str, match_result, pat_regex)) {
      int gourp_a = string(match_result[1]).size();
      int group_b = string(match_result[2]).size();
      int group_c = string(match_result[3]).size();

      return group_c == gourp_a * group_b ? 1 : 0;
    } else {
      return 0;
    }

    return 0;
  }
};

int main() {
  string line;
  Solution s;
  vector<string> lines;

  int target = 0;
  while (getline(cin, line)) {
    if (line.empty()) {
      break;
    }
    if (!target) {
      target = stoi(line);
    } else {
      lines.push_back(line);
    }
  }

  for (int i = 0; i < lines.size(); i++) {
    string str = lines[i];
    string res = s.judge(str) == 1 ? "YES" : "NO";

    if (i == lines.size() - 1) {
      cout << res;
    } else {
      cout << res << endl;
    }
  }
  return 0;
}