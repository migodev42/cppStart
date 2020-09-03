#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;
using std::cout;
using std::cin;
using std::endl;

vector<int> shuffle(vector<int>& nums, int n) {
    /* vector<int> rs;
    for (unsigned int i = 0; i < n;++i) {
        rs.push_back(nums[i]);
        rs.push_back(nums[n + i]);
    }
    return rs; */

    vector<int> rs(nums.size());
    for (decltype(n) i = 0, j = 0; i < n;++i, j += 2) {
        rs[j] = nums[i];
        rs[j + 1] = nums[n + i];
    }
    return rs;
}

int main() {
    vector<int> v = { 2,5,1,3,4,7 };
    int n = 3;
    vector<int> rs = shuffle(v, n);

    for (auto item : rs) {
        cout << item << " ";
    }
    return 0;
}
