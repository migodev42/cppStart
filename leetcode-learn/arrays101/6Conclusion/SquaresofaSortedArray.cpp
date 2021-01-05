#include <vector>
#include <cmath>
#include <ctime>
#include <utility>

using std::vector;
using std::swap;
using std::sqrt;

/* 平方后排序 时间O(nlogn) 空间O(1) */
class Solution {
public:
  int pivot(vector<int>& target, int l, int r) {
    int randidx = l + rand() % (r - l + 1);
    swap(target[randidx], target[r]);

    int sorted = l-1;
    for (int i = l; i < r; ++i) {
      if (target[i] < target[r]) {
        ++sorted;
        swap(target[i], target[sorted]);
      }
    }
    sorted = sorted + 1;
    swap(target[r], target[sorted]);
    return sorted;
  }
  void quickSort(vector<int>& target, int l, int r) {
    if (l < r) {
      int pv = pivot(target, l, r);
      quickSort(target, l, pv - 1);
      quickSort(target, pv + 1, r);
    }
  }
  vector<int> sortedSquares(vector<int>& A) {
    for (auto& i : A) {
      i = i * i;
    }
    srand((unsigned)time(nullptr));
    quickSort(A, 0, A.size() - 1);
    return A;
  }
};