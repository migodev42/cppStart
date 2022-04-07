// https://pintia.cn/problem-sets/994805260223102976/problems/994805320306507776
#include <algorithm>
#include <climits>
#include <iostream>
#include <sstream> // 字符串流
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

/*
废弃思路

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

/*
  将每个数字进行 Callatz
  猜想，从第一次计算开始时（即不记录数字本身）将路径数字记录到一个 Map 中 当 Map
  中存在改数字，则跳过，若不存在该数字则存入 Map

  遍历完所有数字的 Callatz 猜想后得到一个 Map 集，
  再次遍历数字，若该数字没有在 Map 中出现过，即为不能被其他数字覆盖的“关键树”
 */

class Solution {
public:
  unordered_map<int, bool> Callatz(int num) {
    unordered_map<int, bool> result;
    while (num != 1) {
      if (num % 2 == 0) {
        num = num / 2;
      } else {
        num = (num * 3 + 1) / 2;
      }
      result[num] = true;
      // cout << num << " ";
    }
    // cout << endl;
    return result;
  }
  // int CallatzAdvance(int num) { return 0; }
};

// 单行输入
// int main() {
//   int input;
//   cin >> input;

//   Solution s;
//   s.xxMethod(0);
//   return 0;
// }
vector<string> split(string s, string del = " ") {
  vector<string> result;
  int start = 0;
  int end = s.find(del);
  while (end != -1) {
    result.push_back(s.substr(start, end - start));
    // cout << s.substr(start, end - start) << endl;
    start = end + del.size();
    end = s.find(del, start);
  }
  result.push_back(s.substr(start, end - start));
  // cout << s.substr(start, end - start);
  return result;
}

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

bool max_to_min(int i, int j) { return i > j; }

// 多行输入
int main() {
  string line;
  getline(cin, line);
  // int caseCnt = stoi(line);
  getline(cin, line);

  Solution s;
  unordered_map<int, bool> covered;

  vector<string> numbers = split(line, " ");
  for (string num : numbers) {
    covered.merge(s.Callatz(stoi(num)));
  }

  vector<int> result;
  for (string num : numbers) {
    int curr = stoi(num);
    if (!covered[curr])
      result.push_back(curr);
  }

  sort(result.begin(), result.end(), max_to_min);
  for (vector<int>::size_type i = 0; i < result.size(); i++) {
    if (i != result.size() - 1) {
      cout << result[i] << " ";
    } else {
      cout << result[i] << endl;
    }
  }
  
  // 实验代码
  // s.Callatz(3);
  // s.Callatz(5);
  // s.Callatz(6);
  // s.Callatz(7);
  // s.Callatz(8);
  // s.Callatz(11);
  return 0;
}