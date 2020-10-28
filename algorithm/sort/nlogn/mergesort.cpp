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
        if (l >= r)return;
        int mid = (l + r) >> 1;
        mergeSort(nums, l, mid);
        mergeSort(nums, mid + 1, r);

        int left = l, right = mid + 1;
        int pos = 0;
        while (left <= mid && right <= r) {
            if (nums[left] < nums[right]) tmp[pos++] = nums[left++];
            else tmp[pos++] = nums[right++];
        }

        while (left <= mid) {
            tmp[pos++] = nums[left++];
        }

        while (right <= r) {
            tmp[pos++] = nums[right++];
        }
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