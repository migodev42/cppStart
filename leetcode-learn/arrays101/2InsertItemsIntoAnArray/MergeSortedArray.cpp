#include <vector>

using std::vector;
/*
    Input:
    nums1 = [1,2,3,0,0,0], m = 3
    nums2 = [2,5,6],       n = 3

    Output: [1,2,2,3,5,6]
*/

class Solution {
public:
    void move(vector<int>& target, int frompos) {
        for (int i = target.size() - 1; i > frompos; --i) {
            target[i] = target[i - 1];
        }

    }
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int pos1 = 0;
        int pos2 = 0;
        while (pos1 < m && pos2 < n) {
            if (nums1[pos1] < nums2[pos2]) {
                ++pos1;
            }
            else {
                move(nums1, pos1);
                nums1[pos1] = nums2[pos2++];
            }
        }
        while (pos2 < n) {
            nums1[pos1] = nums2[pos2++];            
        }
    }
};