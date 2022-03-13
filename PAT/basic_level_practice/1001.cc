// 1001 害死人不偿命的(3n+1)猜想 (15 分)
// https://pintia.cn/problem-sets/994805260223102976/problems/994805325918486528

#include <iostream>

using namespace std;

class Solution {
public:
  int callatz(int num) {
    int count = 0;

    while (num != 1) {
      bool isEven = num % 2 == 0; // 偶数
      if (isEven)
        num = num / 2;
      else
        num = (3 * num + 1) / 2;
      count++;
    }
    return count;
  }
};

int main() {
  int input;
  // cout << "输入一个数字：" << endl;
  cin >> input;

  Solution s;
  // cout << "结果" << s.callatz(input) << endl;
  cout  << s.callatz(input) << endl;

  return 0;
}
