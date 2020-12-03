#include <vector>
#include <cmath>

using std::floor;
using std::vector;

// 暴力解法：
// class Solution {
// public:
//     int searchInsert(vector<int>& nums, int target) {
//         int i = 0;
//         while (i < nums.size()) {
//             if (target <= nums[i]) return i;
//             ++i;
//         }
//         return nums.size();
//     }
// };

// 二分法
class Solution {
public:
    // int binarySearch(vector<int>& nums, int beg, int end, int target) {
    //     int mid = floor((beg + end) / 2);
    //     // if(target<=)

    // }
    int searchInsert(vector<int>& nums, int target) {
        if (!nums.size()) return 0;
        int beg = 0;
        int end = nums.size() - 1;
        
        while (beg <= end) {
            int mid = floor((beg + end) / 2);
            if(target == nums[mid]){
                return mid;
            }else if(target < nums[mid]){
                end = mid-1;
            }else{
                beg = mid+1;
            }
        }
        return end + 1;
    }
};