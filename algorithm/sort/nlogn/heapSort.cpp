#include <algorithm>
#include <iostream>
#include <vector>

using std::cout;
using std::swap;
using std::vector;

/* TODO */
class Solution {
   private:
    int parent(int i) {
        return i / 2;  // i>>1
    }

    int left(int i) {
        return 2 * i + 1;  // 也可位运算实现 i<<1
    }

    int right(int i) {
        return 2 * i + 2;  // i<<1+1
    }
    void heapify(vector<int>& nums, int idx) {
        int rootlargest = idx;
        int lchild = left(idx);
        int rchild = right(idx);

        if (lchild < nums.size() && nums[lchild] > nums[rootlargest]) {
            rootlargest = lchild;
        }
        if (rchild < nums.size() && nums[rchild] > nums[rootlargest]) {
            rootlargest = rchild;
        }
        if (rootlargest != idx) {
            swap(nums[idx], nums[rootlargest]);
            heapify(nums, rootlargest);
        }
    }

   public:
    void heapSort(vector<int> nums) {
        int size = nums.size();

        /* 建堆 */
        for (int i = size / 2 - 1; i >= 0; --i) {
            heapify(nums, i);
        }        

        /* 完成数组排序 */        
        // for (int i = size - 1; i >= 0; --i) {
        //     swap(nums[0], nums[i]);
        //     heapify(nums, i);
        // }
        
        // 打印结果
        for (int i = 1; i < size; ++i) cout << nums[i] << " ";
    }
};
int main() {
    vector<int> v = {0, 5, 3, 2, 1, 7, 6, 10};
    Solution s;
    s.heapSort(v);
}