// https://pintia.cn/problem-sets/994805260223102976/problems/994805318855278592
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Solution {
public:
  vector<int> parseDigits(int num) {
    vector<int> result;
    while (num > 0) {
      int tmp = num % 10;
      result.push_back(tmp);
      num = num / 10;
    }
    return result;
  };
  string formatNumber(int num) {
    string result;
    vector<int> digits = parseDigits(num);
    int *ones = &digits[0];
    int *tens = &digits[1];
    int *hundreds = &digits[2];
    if (hundreds != NULL) {
      for (int i = 0; i < *hundreds; i++) {
        result += 'B';
      }
    }
    if (tens != NULL) {
      for (int i = 0; i < *tens; i++) {
        result += 'S';
      }
    }
    if (ones != NULL) {
      for (int i = 0; i < *ones; i++) {
        result += to_string(i + 1);
      }
    }
    return result;
  };
};
int main() {
  string line;
  getline(cin, line);
  int num = stoi(line);
  Solution s;
  cout << s.formatNumber(num) << endl;
  return 0;
}