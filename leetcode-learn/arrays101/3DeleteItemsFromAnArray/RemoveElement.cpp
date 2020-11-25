#include <vector>

using std::vector;

class Solution {
public:
    void deletion(vector<int>& target, int frompos) {
        for (int i = frompos + 1; i < target.size(); ++i) {
            target[i - 1] = target[i];
        }
        target.resize(target.size() - 1);
    }
    int removeElement(vector<int>& nums, int val) {
        int i = 0;
        while (i < nums.size()) {
            if (nums[i] == val) {
                deletion(nums, i);
            }
            else {
                ++i;
            }
        }
        return nums.size();
    }
};