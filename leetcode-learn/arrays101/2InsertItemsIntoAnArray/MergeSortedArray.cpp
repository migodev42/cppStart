#include <vector>

using std::vector;

class Solution {
public:
    void resizeAndMove(vector<int>& target, int frompos) {
        target.resize(target.size() + 1);
        for (int i = target.size() - 1; i > frompos; --i) {
            target[i] = target[i - 1];
        }

    }
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {

    }
};