#include <vector>
#include <cstdlib>
#include <ctime>
#include <utility>

using std::rand;
using std::swap;
using std::vector;

class Solution {
public:
  int pivot(vector<int>& nums, int l, int r) {
    // 选择pivot
    int randpv = l + rand() % (r - l + 1);
    swap(nums[randpv], nums[r]);

    // 比较并交换
    // 将比pivot小的数字swap到当前数组(l to r)最前面
    int curPos = l - 1;
    for (int i = l; i < r; ++i) {
      if (nums[i] < nums[r]) {
        ++curPos;
        swap(nums[curPos], nums[i]);
      }
    }

    // 交换结束将pivot置于有序子数组末尾
    swap(nums[curPos + 1], nums[r]);
    return curPos + 1;

  }
  void quickSort(vector<int>& nums, int l, int r) {
    if (l < r) {
      int pos = pivot(nums, l, r);
      quickSort(nums, l, pos - 1);
      quickSort(nums, pos + 1, r);
    }
  }
  vector<int> sortarr(vector<int>& nums) {
    srand((unsigned)time(nullptr));
    quickSort(nums, 0, nums.size() - 1);
  }
};

/* 双指针快排 */
class QuickSort {
public:
  /* 选取pivot, 并排序数组 */
  int pivot(vector<int>& target, int l, int r) {
    int randidx = l + rand() % (r - l + 1);
    swap(target[randidx], target[r]);

    // 比较并交换
    // 将比pivot小的数字swap到当前数组(l to r)最前面
    int sorted = l;
    for (int i = l; i < r; ++i) {
      if (target[i] < target[r]) {
        swap(target[i], target[sorted]);
        ++sorted;
      }
    }
    // 此时的sorted为已排序数组后一位的idx
    // 将最开始的选取的randidx，swap回来
    // 结果是randidx左边的数字全部小于它，右边的数字全部大于它（randidx上的数）
    swap(target[r], target[sorted]);
    return sorted;
  }
  void quickSort(vector<int>& target, int l, int r) {
    if (l < r) {
      int pv = pivot(target, l, r);
      // 此时pv左边的数字全部小于它，右边的数字全部大于它（randidx上的数）
      // 递归对左边和右边的子数组排序，直到 l=r;
      quickSort(target, l, pv - 1);
      quickSort(target, pv + 1, r);
    }
  }
  vector<int> main(vector<int>& nums) {
    srand((unsigned)time(nullptr));
    quickSort(nums, 0, nums.size() - 1);
  }
};