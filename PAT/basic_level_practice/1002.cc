// 1002 写出这个数 (20 分)
// https://pintia.cn/problem-sets/994805260223102976/problems/994805324509200384
// 注意看下数字长度


#include <cctype>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> getSingleDigit(int num) {
    int digit = num % 10;
    return {digit, num / 10};
  };

  string writeTheNumber(string num_str) {
    map<int, string> names = {
        {0, "ling"}, {1, "yi"},  {2, "er"}, {3, "san"}, {4, "si"},
        {5, "wu"},   {6, "liu"}, {7, "qi"}, {8, "ba"},  {9, "jiu"},
    };
    int sum = 0;
    string rs = "";

    auto str_end = num_str.rbegin(), str_begin = num_str.rend();
    while (str_end != str_begin) {
      if (isspace(*str_end))
        continue;
      int curr = *str_end - '0';
      str_end++;
      sum += curr;
    }

    bool first = true;
    while (sum > 0) {
      vector<int> digits = getSingleDigit(sum);
      sum = digits[1];

      if (first) {
        rs = names[digits[0]] + rs; // 最后一个数字不加空格
        first = false;
      } else
        rs = names[digits[0]] + ' ' + rs;
    }

    return rs;
  }
};

int main() {
  string input; // 这里一开始用的 int 然后用的 long long，再然后看下题目发现长度是10^100，所以要改为 string 来存
  cin >> input;
  Solution s;
  cout << s.writeTheNumber(input) << endl;
  return 0;
}