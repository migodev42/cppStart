#include <iostream>
#include <string>
#include <vector>
#include <sstream> // 字符串流
#include <climits>

using namespace std;

class Solution {
public:
  int xxMethod(int num) { return 0; }
};

// 单行输入
// int main() {
//   int input;
//   cin >> input;

//   Solution s;
//   s.xxMethod(0);
//   return 0;
// }

vector<string> getMutiLines() {
  string line;
  vector<string> lines;
  int caseCount = 0;
  while (getline(cin, line)) {
    if (line.empty()) {
      break;
    }
    if (!caseCount) {
      caseCount = stoi(line);
      continue;
    }
    lines.push_back(line);
  }
  return lines;
}

// 多行输入
int main() {
  Solution s;
  vector<string> lines = getMutiLines();
  return 0;
}