#include <iostream>
#include <string>
#include <vector>

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

// 多行输入
int main() {
  string line;
  Solution s;
  vector<string> lines;

  while (getline(cin, line)) {
    if (line.empty()) {
      break;
    }
    lines.push_back(line);
  }
  return 0;
}