#include <climits>
#include <iostream>
#include <sstream> // 字符串流
#include <string>
#include <vector>

using namespace std;

/*

3 5 6 7 8 11 
“不能被其他子串覆盖”，从子串尾部筛选，直到最后只剩一条匹配
1 所有匹配
...
5 4条匹配
此时有两条路径 3 和 10 
继续 3 只剩一条匹配，加入结果集
继续 10 20 ... 17 
11 只剩一条匹配 加入结果集

5 8 4 2 1 
8 4 2 1 
3 5 8 4 2 1 
11 17 26 13 20 10 5 8 4 2 1 
4 2 1 
17 26 13 20 10 5 8 4 2 1 

 */
class Solution {
public:
  int Callatz(int num) {
    while (num != 1) {
      if (num % 2 == 0) {
        num = num / 2;
      } else {
        num = (num * 3 + 1) / 2;
      }
      cout << num << " ";
    }
    cout << endl;
    return 0;
  }
  int CallatzAdvance(int num) { return 0; }
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
  // vector<string> lines = getMutiLines();
  s.Callatz(3);
  s.Callatz(5);
  s.Callatz(6);
  s.Callatz(7);
  s.Callatz(8);
  s.Callatz(11);
  return 0;
}