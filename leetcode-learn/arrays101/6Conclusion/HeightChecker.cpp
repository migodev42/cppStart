#include <vector>
#include <algorithm>

using std::rand;
using std::swap;
using std::vector;

class Solution {
public:
    int pivot(vector<int>& nums, int l, int r){
        int randpv = l + rand() % (r - l + 1);
        swap(nums[randpv], nums[r]);
        
        // 比较并交换
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
    void quickSort(vector<int>& nums, int l, int r){
        if(l<r){
            int pos = pivot(nums, l, r);
            quickSort(nums, l, pos - 1);
            quickSort(nums, pos + 1, r);
        }
    }
    int heightChecker(vector<int>& heights) {
        srand((unsigned)time(nullptr));    
        vector<int> nums = vector<int>(heights.begin(),heights.end());
        quickSort(nums, 0, nums.size() - 1);
        int result = 0;
        for(int i = 0; i<nums.size(); ++i){
            if(nums[i]!=heights[i]){
                ++result;
            }
        }
        return result;
    }
};