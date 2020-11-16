#include <vector>

using std::vector;

class Solution {
public:
    bool hasEvenDigits(int num) {
        int cnt = 0;
        while (num > 0) {
            num = num / 10;
            ++cnt;
        }
        return cnt % 2 == 0;
    }
    int findNumbers(vector<int>& nums) {
        int rs = 0;
        for (int& item : nums) {
            if (hasEvenDigits(item)) {
                ++rs;
            }
        }
        return rs;
    }
};