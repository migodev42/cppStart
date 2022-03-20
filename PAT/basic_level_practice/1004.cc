// https://pintia.cn/problem-sets/994805260223102976/problems/994805321640296448

#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <climits>

using namespace std;

class Solution {
public:
  int xxMethod(int num) { return 0; }
};

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
  string line;
  vector<string> lines;
  int caseCount = 0;

  int max_score = INT_MIN;
  int min_score = INT_MAX;
  string max_score_student;
  string min_score_student;
  while (getline(cin, line)) {
    if (line.empty()) {
      break;
    }

    if (!caseCount) {
      caseCount = stoi(line);
      continue;
    }

    istringstream iss(line);
    string stu_name;
    string stu_number;
    int score;

    iss >> stu_name >> stu_number >> score;
    string student_info = stu_name + " " + stu_number;
    if (score > max_score) {
      max_score_student = student_info;
      max_score = score;
    }
    if (score < min_score) {
      min_score_student = student_info;
      min_score = score;
    }
  }

  cout << max_score_student << endl;
  cout << min_score_student << endl;
  return 0;
}