#include <vector>
#include <cstdlib>
#include <ctime>
#include <utility>

using std::rand;
using std::swap;
using std::vector;

class Solution {
public:
    vector<int> tmp;
    void mergeSort(vector<int>& nums, int l, int r) {
        // 当每次取的mid（l）与r位置相同时，就无法再进行分割了，即递归结束条件
        if (l >= r)return;
        
        // 使用位运算取中间位置下标， >> 1 等价于 /2
        int mid = (l + r) >> 1; 

        // 使用双指针递归分割数组，类似于二分查找
        mergeSort(nums, l, mid);
        mergeSort(nums, mid + 1, r);


        // 每一层已经无法分割时或者已经排序完成时，开始上一层的排序，自底向上
        int left = l, right = mid + 1;
        int pos = 0;

        // 将当前l到r的数组切分为两个数组，每一轮将小的数字放到结果中
        // 由于是自底向上，所以从mid分割开左右的数组都是有序的
        while (left <= mid && right <= r) {
            if (nums[left] < nums[right]) tmp[pos++] = nums[left++];
            else tmp[pos++] = nums[right++];
        }

        // 两个数组比较后，任一有剩余的就直接放入结果中
        while (left <= mid) {
            tmp[pos++] = nums[left++];
        }

        while (right <= r) {
            tmp[pos++] = nums[right++];
        }

        // 将本层排好序的一段数组tmp，放回原数组
        for(int pos = 0; pos < r-l+1; ++pos) {
            nums[l + pos] = tmp[pos];
        }

    }
    vector<int> sortArray(vector<int>& nums) {
        tmp.resize(nums.size(), 0);
        mergeSort(nums, 0 , nums.size()-1);
        return nums;
    }
};